/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:05:28 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/05 00:04:24 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

typedef struct s_data {
	int		bit_count;
	char	current_char;
}	t_data;

t_data	g_data;

typedef struct s_server
{
	int	current_char;
	int	bits_received;
}	t_server;

void	send_message(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	g_data.current_char = g_data.current_char << 1;
	if (sig == SIGUSR1)
		g_data.current_char = g_data.current_char | 1;
	g_data.bit_count++;
	if (g_data.bit_count == 8)
	{
		ft_putchar_fd(g_data.current_char, STDOUT_FILENO);
		g_data.current_char = 0;
		g_data.bit_count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (sigemptyset(&sa.sa_mask) == FAIL)
		return (ERROR);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = send_message;
	if (sigaction(SIGUSR1, &sa, NULL) == FAIL)
		return (ERROR);
	if (sigaction(SIGUSR2, &sa, NULL) == FAIL)
		return (ERROR);
	while (TRUE)
		pause();
	return (SUCCESS);
}
