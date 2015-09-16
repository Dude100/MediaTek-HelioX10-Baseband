[Note]

For any modification of *.h.template or *.c.template, there are some rules to follow as below:

1. tools\sysgen2.pl replaces the pattern [AUTOGEN_xxx] in templates every time you perform m sysgen, sys_auto_gen or new.
In this pattern, xxx means A-Z, a-z, 0-9, and _ .
xxx will be the function name in sysgen2.pl.

2. If you want to comment this pattern in templates, kindly use 
#if 0
#endif 
to comment it.

3. Files under custom\system\[Project]\ with the pattern:[MOLY12345678], [MAUI_12345678] or [MANUAL-CHECKIN] still won't be replaced by the templates.

4. The template folder can't accept xxx.c and xxx.c.template which exist simultaneously.