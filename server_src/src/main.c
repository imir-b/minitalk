/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:05:28 by vbleskin          #+#    #+#             */
/*   Updated: 2026/01/04 03:09:42 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	return (SUCCESS);
}
