# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 12:21:15 by mcutura           #+#    #+#              #
#    Updated: 2023/05/05 14:00:12 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		 ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c \
		 ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		 ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		 ft_toupper.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		 ft_putnbr_fd.c ft_strmapi.c ft_isalpha.c ft_isdigit.c ft_striteri.c
BONUSFILES := ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			  ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstmap.c
OBJS := $(FILES:%.c=%.o)
BONUSOBJS := $(BONUSFILES:%.c=%.o)
HEADER := libft.h
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

.PHONY: all bonus clean fclean re

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME) bonus

bonus: $(BONUSOBJS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
