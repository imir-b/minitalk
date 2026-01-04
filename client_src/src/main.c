/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:14:04 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/05 00:08:56 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_char(char c, int pid)
{
	int	ret_kill;
	int	pos;

	pos = 8;
	while (--pos >= 0)
	{
		if (((c >> pos) & 1) == 1)
			ret_kill = kill((pid_t)pid, SIGUSR1);
		else
			ret_kill = kill((pid_t)(pid), SIGUSR2);
		usleep(400);
		if (ret_kill == FAIL)
			return (ERROR);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
		return (ERROR);
	pid = ft_atoi((const char *)av[1]);
	msg = av[2];
	while (*msg)
	{
		send_char(*msg, pid);
		msg++;
	}
	return (SUCCESS);
}
