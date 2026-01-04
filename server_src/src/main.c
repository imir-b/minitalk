/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:05:28 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/04 03:46:57 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

typedef struct sigaction
{
	sa_flags = SA_SIGINFO;
}	t_act;

int	main(void)
{
	pid_t		pid;
	sigset_t	set;
	t_act		act;

	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	if (sigemptyset(&set) == FAIL)
		return (ERROR);
	sigaddset(&set, pid);
	sigaction(pid, act, NULL);
	while (TRUE)
		pause();
	return (SUCCESS);
}
