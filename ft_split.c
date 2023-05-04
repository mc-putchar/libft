/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:00:52 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/03 16:50:59 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s++ == c)
		{
			if (word)
			{
				++count;
				word = 0;
			}
		}
		else
			++word;
	}
	if (word)
		++count;
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**spl;
	int		count;
	int		word;
	int		i;

	count = count_words(s, c);
	spl = malloc(sizeof(char *) * (count + 1));
	if (!spl)
		return (NULL);
	i = 0;
	word = 0;
	while (i < count)
	{
		if ((*s == c || !*s) && word)
		{
			spl[i++] = ft_substr(s - word, 0, word);
			word = 0;
		}
		else if (*s != c)
			++word;
		++s;
	}
	spl[i] = NULL;
	return (spl);
}
