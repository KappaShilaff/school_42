NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc  $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I srcs/libft/includes

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	srcs/libft/

CFILE =		ft_printf.c uflag.c idflag.c oxperflag.c scflag.c pflag.c fflag.c bin2str.c flflag.c norm_printf.c\


CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re