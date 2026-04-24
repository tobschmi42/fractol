CC=cc
CFLAGS=-Wextra -Wall -Werror -MMD -MP

SRCS = main.c colors.c mandelbrot.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)


DPNDC = fractol.h
NAME = fractol

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -lmlx -lXext -lX11 -lm

%.o: %.c $(DPNDC)
	$(CC) $(CFLAGS) -c $< -O1 -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all

-include $(DEPS)