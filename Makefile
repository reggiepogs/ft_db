NAME	= ft_db

SRCS	=	main.c \
			ft_db.c \
			options.c \

LIBDIR 	=	./libft/
LIBFT	=	$(addprefix $(LIBDIR), libft.a)

all: $(SRCS) $(LIBFT)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRCS) -L$(LIBDIR) -lft

$(LIBFT):
	make -c $(LIBDIR)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
 
.PHONY: all clean clean re
