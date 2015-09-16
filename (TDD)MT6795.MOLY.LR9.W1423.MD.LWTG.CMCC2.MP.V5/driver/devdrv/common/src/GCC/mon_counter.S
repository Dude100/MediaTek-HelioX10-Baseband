#include "asm_def.h"

.thumb
.syntax unified

@void mon_counter_enable(unsigned int ifenable)
@{
   FUNC_ATTR(mon_counter_enable)
   .global  mon_counter_enable
mon_counter_enable:
   @ set cycle divide value
   CMP    r0, 1
   MRC    p15, 0, r3, c9, c12, 0    @read PMNC Performance MoNitor Control Register
   ORREQ  r3, r3, 0x01
   BICNE  r3, r3, 0x01
   MCR    p15, 0, r3, c9, c12, 0

   BX     lr
.size mon_counter_enable, .-mon_counter_enable
@}


@void mon_counter_set_cycle(unsigned int value, unsigned int divide)
@{
   FUNC_ATTR(mon_counter_set_cycle)
   .global  mon_counter_set_cycle
mon_counter_set_cycle:
   @ set cycle divide value
   CMP    r1, 1
   MRC    p15, 0, r3, c9, c12, 0    @read PMNC Performance MoNitor Control Register
   ORREQ  r3, r3, 0x08
   BICNE  r3, r3, 0x08
   MCR    p15, 0, r3, c9, c12, 0

   @ set cycle counter value
   MCR    p15, 0, r0, c9, c13, 0

   @ start cycle counter
   MOV    r3, #0x80000000
   MCR    p15, 0, r3, c9, c12, 1    @write CNTENS

   BX     lr
.size mon_counter_set_cycle, .-mon_counter_set_cycle
@}

@unsigned int mon_counter_get_cycle(void)
@{
   FUNC_ATTR(mon_counter_get_cycle)
   .global  mon_counter_get_cycle
mon_counter_get_cycle:
   @ get cycle counter value
   MRC    p15, 0, r0, c9, c13, 0
   BX     lr
.size mon_counter_get_cycle, .-mon_counter_get_cycle
@}

@clear event counter
@void mon_counter_clear_event_counter(unsigned int count_id)
@{
   FUNC_ATTR(mon_counter_clear_event_counter)
   .global  mon_counter_clear_event_counter
mon_counter_clear_event_counter:
   @set event id
   MRC    p15, 0, r3, c9, c12, 5    @read PMNXSEL
   BFI    r3, r0, #0, #5
   MCR    p15, 0, r3, c9, c12, 5    @write PMNXSEL

   @set event count value = 0
   MOV    r1, 0
   MCR    p15, 0, r1, c9, c13, 2

   BX     lr
.size mon_counter_clear_event_counter, .-mon_counter_clear_event_counter
@}

@
@void mon_counter_start_event_mask(unsigned int count_mask)
@{
   FUNC_ATTR(mon_counter_start_event_mask)
   .global  mon_counter_start_event_mask
mon_counter_start_event_mask:
   @start event counter
   MCR    p15, 0, r0, c9, c12, 1    @write CNTENS
   BX     lr
.size mon_counter_start_event_mask, .-mon_counter_start_event_mask
@}

@void mon_counter_stop_event_mask(unsigned int count_mask)
@{
   FUNC_ATTR(mon_counter_stop_event_mask)
   .global  mon_counter_stop_event_mask
mon_counter_stop_event_mask:
   @start event counter
   MCR    p15, 0, r0, c9, c12, 2    @write PMNC Performance MoNitor Control Register
   BX     lr
.size mon_counter_stop_event_mask, .-mon_counter_stop_event_mask
@}


@void mon_counter_set_eventid(unsigned int count_id, unsigned int eventid)
@{
   FUNC_ATTR(mon_counter_set_eventid)
   .global  mon_counter_set_eventid
mon_counter_set_eventid:

   @set event id
   MRC    p15, 0, r3, c9, c12, 5    @read PMNXSEL
   BFI    r3, r0, #0, #5
   MCR    p15, 0, r3, c9, c12, 5    @write PMNXSEL

   @set event id
   MCR    p15, 0, r1, c9, c13, 1    @write EVTSELx

   BX     lr
.size mon_counter_set_eventid, .-mon_counter_set_eventid
@}


@unsigned int mon_counter_get_event_value(unsigned int count_id)
@{
   FUNC_ATTR(mon_counter_get_event_value)
   .global  mon_counter_get_event_value
mon_counter_get_event_value:
   @set event id
   MRC    p15, 0, r3, c9, c12, 5    @read PMNXSEL
   BFI    r3, r0, #0, #5
   MCR    p15, 0, r3, c9, c12, 5    @write PMNXSEL

   @get event counter value
   MRC    p15, 0, r0, c9, c13, 2    @write Counter Value

   BX     lr
.size mon_counter_get_event_value, .-mon_counter_get_event_value
@}

   .end

