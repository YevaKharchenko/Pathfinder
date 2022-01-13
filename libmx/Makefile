NAME = libmx.a

MKDIR = mkdir -p
AR = ar -rcs
RM = rm -rf 

.DEFAULT_GOAL = all

INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/

CC = clang
WFLAGS = -Wall -Wextra -Werror -Wpedantic
HFLAGS = -I$(INC_DIR)

COMPILE = $(CC) -std=c11 -pipe $(WFLAGS) $(HFLAGS)

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


all: $(NAME)

$(OBJ_DIR):
	@$(MKDIR) $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(COMPILE) -o $@ -c $<
	
$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) $@ $(OBJ)

uninstall: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) *.a

reinstall: uninstall all
