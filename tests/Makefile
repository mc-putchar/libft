# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 02:43:48 by mcutura           #+#    #+#              #
#    Updated: 2025/07/06 02:54:01 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libunit.a
LIBFT := ../libft.a

RM := rm -f
LN := ln -sf

.PHONY: framework test clean fclean
$(NAME): | framework
	$(LN) framework/$@ $@

framework:
	@$(MAKE) -C $@

test: $(NAME) $(LIBFT)
	@$(MAKE) -C tests $(MAKECMDGOALS)

clean fclean:
	@$(MAKE) -C framework $(MAKECMDGOALS)
	@$(MAKE) -C tests $(MAKECMDGOALS)
	@$(RM) $(NAME)

re: fclean
	$(MAKE) $(NAME)
