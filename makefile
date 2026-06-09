PROJECTNAME = 2048

CC = lcc

CFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf--debug -c

LDFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf--debug -Z -Wm-yoA -Wm-yn"2048"

SRC = src/main.c src/board.c src/font.c src/screens.c src/utils.c src/sprites/block_tiles.c src/sprites/number_tiles.c src/sprites/logo_data.c src/sprites/logo_map.c src/sprites/trophy_data.c src/sprites/trophy_map.c

OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR = build

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

all: $(BUILD_DIR)/$(PROJECTNAME).gb

$(BUILD_DIR)/$(PROJECTNAME).gb: $(OBJ)

	$(CC) $(LDFLAGS) -o $@ $(OBJ)
