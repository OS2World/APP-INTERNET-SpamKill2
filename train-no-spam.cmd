/* rexx */

call RxFuncAdd 'SysLoadFuncs', 'RexxUtil', 'SysLoadFuncs'
call SysLoadFuncs

parse arg BaseDir

/* Find msg files */
say 'Scanning for message files...'
call SysFileTree BaseDir || '\*.MSG', 'file', 'FSO'
say 'Found ' || file.0 || ' message files.'

parse value SysCurPos() with row col
dot = file.0 / 100
percent = 0

say 'One dot every' dot 'messages.'
say 'Parsing message files...'

n = 0;

do i=1 to file.0
  if n>=dot then do
    call SysCurPos row-1, col
    say 'Done ' || percent || '%'
    n = 0
    percent = percent + 1
  end
  n = n + 1
  '@SpamKill2 -l -n -v < ' file.i
end

call SysCurPos row-1, 0
say 'Done 100%'
call SysCurPos row, 0

say 'Done."'
