lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o game.o ./src/main.c 
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -o 2048.gb game.o

@REM del *.o
@REM del *.map
@REM del *.lst
@REM del *.sym
@REM del *.asm
@REM del *.cdb
@REM del *.ihx
@REM del *.adb