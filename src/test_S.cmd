/* rexx */
GOODDIR0="T_good"
SPAMDIR0="T_spam"
UNSURE0="T_unsure"
call RxFuncAdd 'SysLoadFuncs', 'RexxUtil', 'SysLoadFuncs'
call SysLoadFuncs

parse arg BaseDir GOODDIR SPAMDIR UNSURE
if BaseDir ="" then
do
SAY "Test and sort MSG files"
SAY "test source dir and move MSG files to good, spam or unsure dirs"
SAY "Usage: test_S BaseDir [[GOODDIR] [[SPAMDIR] [UNSUREDIR]]]"
SAY "Default:"
SAY "GOODDIR  =" GOODDIR0
SAY "SPAMDIR  =" SPAMDIR0
SAY "UNSUREDIR=" UNSURE0
return
end
if GOODDIR="" then 
do
GOODDIR=GOODDIR0
end
if SPAMDIR="" then 
do
SPAMDIR=SPAMDIR0
end
if UNSURE="" then 
do
UNSURE=UNSURE0
end

/* Find msg files */
say 'Scanning for message files...'
call SysFileTree BaseDir || '\*.MSG', 'file', 'FSO'
say 'Found ' || file.0 || ' message files.'

parse value SysCurPos() with row col
dot = file.0 / 100
percent = 0
T0=time('E') 
say 'Parsing message files...'

n = 0;

do i=1 to file.0
  if n>=dot then do
/*    call SysCurPos row-1, col */
/*    say 'Done ' || percent || '%' time('E') */
    n = 0
    percent = percent + 1
  end
  n = n + 1
'@SpamClient  -v -3 -I' file.i
/* say 'RC=' rc  file.i */
cod=RC
FILNAME=FILESPEC("name",file.i)
/* say 'RC=' cod  "File=" FILNAME */

if cod = 1 then
do
newfname=SPAMDIR||'\'||FILNAME 
'@move ' file.i newfname
SAY 'SPAM'
end

if cod = 2 then
do
newfname=GOODDIR||'\'||FILNAME 
'@move ' file.i newfname
SAY 'Good'
end

if cod = 3 then
do
newfname=UNSURE||'\'||FILNAME 
'@move ' file.i newfname
SAY 'UNSURE'
end

end
say ' '
call SysCurPos row-1, 0
say 'Done 100%'
call SysCurPos row, 0

say 'Done in' time('E') 'sec'
