/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:26:56 by mcutura           #+#    #+#             */
/*   Updated: 2024/03/15 15:03:41 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (-1);
	size = 0;
	while (lst && ++size)
		lst = lst->next;
	return (size);
}
