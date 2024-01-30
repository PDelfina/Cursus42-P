# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dparada <dparada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:33:13 by dparada           #+#    #+#              #
#    Updated: 2024/01/30 10:32:06 by dparada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
USER    = dparada
MLX42   = lib/MLX42
LIBFT   = lib/LIBFT
CFLAGS  = -Wall -Wextra -Werror -g
SRC_DIR = src/
OBJ_DIR = obj/
SRC_DIR_BONUS = src_bonus/
CC      = gcc

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRC_FILES = fractals main print_fractal utils hook colores \
colores_iters mouse

SRC_FILES_BONUS = burningship_bonus colores_bonus colores_iters_bonus hook_bonus \
main_bonus mouse_bonus fractals_bonus print_fractal_bonus utils_bonus

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

OBJF = .cache_exists

all: $(NAME)

$(NAME):	compiling $(OBJ)
			@echo
			@make all -C $(LIBFT)
			@echo "$(GREEN)Compiling MLX42$(RESET)"
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(MAGENTA)Fract_ol compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

bonus:		compiling_bonus $(OBJ_BONUS)
			@echo
			@make all -C $(LIBFT)
			@echo "$(GREEN)Compiling MLX42$(RESET)"
			@make -C $(MLX42)
			@$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
			@echo "$(MAGENTA)Fract_ol bonus compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR_BONUS)%.c | $(OBJF)
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

compiling:
			@echo "$(YELLOW)Compiling FRACT-OL!$(RESET)"

compiling_bonus:
			@echo "$(YELLOW)Compiling FRACT-OL bonus!$(RESET)"
clean:
			@rm -frf $(OBJ_DIR)
			@rm -fef $(OBJ_BONUS)
			@make clean -C $(MLX42)
			@make clean -C $(LIBFT)
			@echo "$(RED)Cleaning libraries MLX and LIBFT.$(RESET)"
			@echo "$(RED)Cleaning fract_ol executables.$(RESET)"
			

fclean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(NAME)
			@make fclean -C $(MLX42)
			@make fclean -C $(LIBFT)
			@echo "$(RED)Fcleaning libraries MLX and LIBFT.$(RESET)"
			@echo "$(RED)Fcleaning fract_ol.$(RESET)"

re: fclean all
			@echo "$(YELLOW)Fract_ol recompiled$(RESET)"

norm:
			@echo "$(YELLOW)Norminette of Fract_ol files & BONUS.$(RESET)"
			@norminette $(SRC)
			@norminette $(SRC_BONUS)
			@echo 
			@echo "$(YELLOW)Norminette of LIBFT.$(RESET)"
			@norminette $(LIBFT)
						
.PHONY: all clean fclean re norm bonus compiling compiling_bonus

