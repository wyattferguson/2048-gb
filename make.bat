lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/main.o ./src/main.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/board.o ./src/board.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/font.o ./src/font.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/screens.o ./src/screens.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/utils.o ./src/utils.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/block_tiles.o ./src/sprites/block_tiles.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/number_tiles.o ./src/sprites/number_tiles.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/logo_data.o ./src/sprites/logo_data.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/logo_map.o ./src/sprites/logo_map.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/trophy_data.o ./src/sprites/trophy_data.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/trophy_map.o ./src/sprites/trophy_map.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -o ./2048.gb ./build/main.o ./build/board.o ./build/font.o ./build/screens.o ./build/utils.o ./build/block_tiles.o ./build/number_tiles.o ./build/logo_data.o ./build/logo_map.o ./build/trophy_data.o ./build/trophy_map.o