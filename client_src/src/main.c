/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:14:04 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/04 03:56:39 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		pid;
	int		bit;
	int		ret_kill;
	char	*msg;

	if (ac != 3)
		return (ERROR);
	pid = ft_atoi((const char *)av[1]);
	msg = av[2];
	while (*msg)
	{
		bit = *msg << 1;
		if (bit == 1)
			ret_kill = kill((pid_t)pid, SIGUSR1);
		else if (bit == 0)
			ret_kill = kill((pid_t)(pid), SIGUSR2);
		if (ret_kill == FAIL)
			return (ERROR);
	}
	while (TRUE)
		pause();
	return (SUCCESS);
}
