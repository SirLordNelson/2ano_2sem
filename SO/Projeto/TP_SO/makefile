# File: makefile
CC = gcc
CFLAGS = -Iinclude `pkg-config --cflags glib-2.0`
LDFLAGS = `pkg-config --libs glib-2.0`
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TMP_DIR = tmp
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Colors
NO_COLOR = \033[m
COMPILING_COLOR = \033[0;33m
LINKING_COLOR = \033[0;34m
DELETING_COLOR = \033[0;31m
CHECKING_COLOR = \033[0;36m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
COMPILING_STRING = "[COMPILING]"
LINKING_STRING = "[LINKING]"
DELETING_STRING = "[DELETING]"
CHECKING_STRING = "[CHECKING]"
OK_STRING = "[OK]"
ERROR_STRING = "[ERROR]"

all: check folders $(BIN_DIR)/dserver $(BIN_DIR)/dclient

check:
	@printf "%b" "$(CHECKING_COLOR)$(CHECKING_STRING) Checking for required tools...$(NO_COLOR)\n"
	@command -v $(CC) >/dev/null 2>&1 || { printf "%b" "$(ERROR_COLOR)$(ERROR_STRING) gcc not found!$(NO_COLOR)\n"; exit 1; }
	@command -v pkg-config >/dev/null 2>&1 || { printf "%b" "$(ERROR_COLOR)$(ERROR_STRING) pkg-config not found!$(NO_COLOR)\n"; exit 1; }
	@pkg-config --exists glib-2.0 || { printf "%b" "$(ERROR_COLOR)$(ERROR_STRING) glib-2.0 not found!$(NO_COLOR)\n"; exit 1; }
	@printf "%b" "$(OK_COLOR)$(OK_STRING) All checks passed!$(NO_COLOR)\n"

folders:
	@mkdir -p $(SRC_DIR) $(INCLUDE_DIR) $(OBJ_DIR) $(BIN_DIR) $(TMP_DIR)

$(BIN_DIR)/dserver: $(OBJ_DIR)/dserver.o $(OBJ_DIR)/document.o
	@printf "%b" "$(LINKING_COLOR)$(LINKING_STRING) Building executable 'dserver'$(NO_COLOR)\n"
	@$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Executable 'dserver' created successfully$(NO_COLOR)\n"

$(BIN_DIR)/dclient: $(OBJ_DIR)/dclient.o $(OBJ_DIR)/document.o
	@printf "%b" "$(LINKING_COLOR)$(LINKING_STRING) Building executable 'dclient'$(NO_COLOR)\n"
	@$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Executable 'dclient' created successfully$(NO_COLOR)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "%b" "$(COMPILING_COLOR)$(COMPILING_STRING) Compiling $<$(NO_COLOR)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "%b" "$(DELETING_COLOR)$(DELETING_STRING) Removing object files and executables$(NO_COLOR)\n"
	@rm -f $(OBJ_DIR)/* $(TMP_DIR)/* $(BIN_DIR)/*
	@printf "%b" "$(OK_COLOR)$(OK_STRING) Clean completed$(NO_COLOR)\n"