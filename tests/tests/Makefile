NAME := unit_test
SRCS := main
SRCS += $(addprefix ft_atoi/, \
	00_launcher \
	01_small_test \
	02_negative_nums \
	03_full_int_range_test \
)
SRCS += $(addprefix ft_strlen/, \
	00_launcher \
	01_basic_test \
	02_null_test \
	03_bigger_str_test \
)
SRCS += $(addprefix ft_printf/, \
	00_launcher \
	01_basic \
	02_null \
	03_char \
	04_string \
)
BINS := $(SRCS:%=%.o)
LIBUNITDIR := ../framework
LIBUNIT := ../libunit.a
LIBFTDIR := ../..
LIBFT := $(LIBFTDIR)/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c99 -Wconversion -Wshadow
CPPFLAGS := -I$(LIBUNITDIR) -I$(LIBFTDIR)/include
LDFLAGS := -L$(LIBUNITDIR) -L$(LIBFTDIR)
LDLIBS := -lunit -lft
debug: CFLAGS += -ggdb3 -Og
debug: CPPFLAGS += -DDEBUG

.PHONY: all clean debug fclean re test
all: $(NAME)
debug: all
$(NAME): $(LIBUNIT) $(BINS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(BINS) -o $@ $(LDFLAGS) $(LDLIBS)
$(LIBUNIT):
	$(MAKE) -C $(LIBUNITDIR)
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -w $(CPPFLAGS) -c $< -o $@
clean:
	rm -fr $(BINS)
fclean: clean
	rm -fr $(NAME)
re: fclean all
test:
	@$(MAKE) all --silent
	@./$(NAME)
