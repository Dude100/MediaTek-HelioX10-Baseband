; If assembled with TASM the variable {CONFIG} will be set to 16
; If assembled with ARMASM the variable {CONFIG} will be set to 32
; Set the variable THUMB to TRUE or false depending on whether the
; file is being assembled with TASM or ARMASM.

        GBLL    THUMB
        GBLL    ARM
    [ {CONFIG} = 16
THUMB   SETL    {TRUE}
ARM     SETL    {FALSE}

; If assembling with TASM go into 32 bit mode as the Armulator will
; start up the program in ARM state.

        CODE32
    |
THUMB   SETL    {FALSE}
ARM     SETL    {TRUE}
    ]

; /*----------------------------*/
; /*  Definitions               */
; /*----------------------------*/

   IF  (:LNOT: :DEF: SINGLE_BANK_SUPPORT)
      GBLL         SINGLE_BANK_SUPPORT
SINGLE_BANK_SUPPORT   SETL    {FALSE}
   ENDIF


; /*----------------------------*/
; /*  Export functions          */
; /*----------------------------*/

   EXPORT  INT_GetCurrentSP

   AREA |C$$code|, CODE, READONLY
|x$codeseg|

   IF SINGLE_BANK_SUPPORT
   AREA |C$$code|, CODE, READONLY
   ENDIF 
   

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_GetCurrentSP                                                 */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Get the value of the current sp register.                        */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      current sp                                                       */
;/*************************************************************************/
; int INT_GetCurrentSP(VOID)
; {
INT_GetCurrentSP
   
   MOV   r0, sp                             ; get the current stack pointer

   [ THUMB
   BX    lr                                 ; Return to caller
   |
   MOV   pc,lr                              ; Return to caller
   ]
;}

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_SwitchStackAndBranch                                         */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Switch current stack pointer to new_stack and then run           */
;/*      func(argv).                                                      */
;/*                                                                       */
;/* CALLED BY                                                             */
;/*      INT_SwitchStackToRun                                             */
;/*                                                                       */
;/* CALLS                                                                 */
;/*      None                                                             */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      new_stack      the new stack pointer which want to switch to     */
;/*      func           the pointer of function which want to run         */
;/*      argc           the number of arguments of func                   */
;/*      argv           the list of arguments                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      The reture value of func                                         */
;/*************************************************************************/
; kal_uint32 INT_SwitchStackAndBranch(kal_uint32 new_stack, kal_func_ptr func, kal_uint32 argc, va_list argv)
; {
INT_SwitchStackAndBranch
   EXPORT   INT_SwitchStackAndBranch
   
   STMDB    SP!, {R4-R7, LR}

   MOV      R7, SP                          ; Backup original SP in R7
   MOV      R6, R3                          ; Load the poitner of argv
   MOV      R5, R0                          ; Backup new SP in R5
   SUBS     R2, R2, #4                      ; Check if need to copy stack?
   BLS      skip_copy_stack

   ADD      R6, R6, #16
   SUB      R5, R0, R2, LSL #2              ; Reserve new stack to store arg4~n

copy_stack
   LDRHI    R4, [R6], #4                    ; Copy arg4~n from argv to new stack
   STRHI    R4, [R5], #4
   CMP      R0, R5
   BHI      copy_stack

   SUB      R5, R0, R2, LSL #2              ; Change new stack pointer

skip_copy_stack
   MOV      R6, R1                          ; Backup function pointer
   MOV      R4, R3                          ; Backup the pointer of argv;

   LDR      R0, [R4]                        ; Setup arguments of procedure call
   LDR      R1, [R4, #4]
   LDR      R2, [R4, #8]
   LDR      R3, [R4, #12]

   MOV      SP, R5                          ; Switch to new stack
   ADR      lr, func_return
   BX       R6                              ; Procedure call
func_return
   MOV      SP, R7                          ; Switch back to old stack

   LDMIA    SP!, {R4-R7, PC}
;}


   END