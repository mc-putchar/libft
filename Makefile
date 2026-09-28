# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 12:21:15 by mcutura           #+#    #+#              #
#    Updated: 2025/07/06 02:54:42 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCDIR := src
BINDIR := build
INCDIR := include
TESTDIR := tests

SRC :=
vpath %.c $(SRCDIR)
SRC += ft_atoi.c
SRC += ft_atod.c
SRC += ft_bzero.c
SRC += ft_calloc.c
SRC += ft_isalnum.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isint.c
SRC += ft_isnumber.c
SRC += ft_isprint.c
SRC += ft_itoa.c
SRC += ft_lstadd_back.c
SRC += ft_lstadd_front.c
SRC += ft_lstclear.c
SRC += ft_lstdelone.c
SRC += ft_lstiter.c
SRC += ft_lstlast.c
SRC += ft_lstmap.c
SRC += ft_lstnew.c
SRC += ft_lstsize.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memmove.c
SRC += ft_memrchr.c
SRC += ft_memset.c
SRC += ft_putchar_fd.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr_fd.c
SRC += ft_split.c
SRC += ft_splits.c
SRC += ft_strchr.c
SRC += ft_strdup.c
SRC += ft_striteri.c
SRC += ft_strjoin.c
SRC += ft_strlcat.c
SRC += ft_strlcpy.c
SRC += ft_strlen.c
SRC += ft_strmapi.c
SRC += ft_strncmp.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c
SRC += ft_strtrim.c
SRC += ft_substr.c
SRC += ft_tolower.c
SRC += ft_toupper.c

ifndef NO_GNL
	SRC += get_next_line.c
endif
ifndef NO_PRINTF
	SRC += ft_printf.c ft_printf_utils.c ft_printf_converters.c \
		ft_printf_converters_hex.c ft_printf_flags.c
endif
ifndef NO_ERROR
	SRC += ft_error.c
endif

OBJ := $(SRC:.c=.o)
OBJ := $(addprefix $(BINDIR)/, $(OBJ))

DEPS := $(OBJ:.o=.d)
-include $(DEPS)

CC := cc
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c99
# CFLAGS += -march=native -O2
CPPFLAGS := -I$(INCDIR)

debug: DEBUG := 1
debug: CFLAGS += -ggdb3 -Og

AR := ar
ARFLAGS := src
MKDIR := mkdir -p
RM := rm -f

.PHONY: all clean fclean re debug test

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

$(BINDIR)/%.o: %.c |$(BINDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BINDIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJ)
	$(RM) -r $(BINDIR)
	$(MAKE) -C $(TESTDIR) $(MAKECMDGOALS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(TESTDIR) $(MAKECMDGOALS)

re:
	$(MAKE) fclean
	$(MAKE) all

debug: fclean
	DEBUG=1 $(MAKE) all

test: $(NAME)
	$(MAKE) -C $(TESTDIR) $(MAKECMDGOALS)
