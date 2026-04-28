CC=cc
CFLAGS=-Wextra -Wall -Werror -MMD -MP

SRCS = main.c colors.c mandelbrot.c testing.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
LIBFT = ./libft/libft.a


DPNDC = fractol.h
NAME = fractol

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -lmlx -lXext -lX11 -lm

%.o: %.c $(DPNDC)
	$(CC) $(CFLAGS) -c $< -O1 -o $@

clean:
	rm -f $(OBJS) $(DEPS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: re fclean clean all

-include $(DEPS)