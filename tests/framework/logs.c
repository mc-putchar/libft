/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:48:08 by mcutura           #+#    #+#             */
/*   Updated: 2024/11/12 00:25:56 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libunit.h"

#define LOGBUF_SIZE	4096

// TODO: Rewrite for multi-source multi-destination with polling
int	open_log(char const *filename)
{
	int	fd;

	if (!filename)
		return (-1);
	fd = creat(filename, 0664);
	if (fd < 0)
		return (throw_error(-1, "Error: could not open file specified.\n"));
	return (fd);
}

void	handle_log(int log, int pipe)
{
	char	logbuf[LOGBUF_SIZE];
	ssize_t	rb;
	ssize_t	wb;
	ssize_t	lb;

	while (1)
	{
		lb = 0;
		rb = read(pipe, logbuf, LOGBUF_SIZE);
		if (rb < 1 && (close(pipe), 1))
			return ;
		while (lb < rb)
		{
			wb = write(log, logbuf, (size_t)(rb - lb));
			if (wb < 1 && (close(log), 1))
				return ;
			lb += wb;
		}
	}
}
