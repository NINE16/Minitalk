/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:08:12 by nnemeth           #+#    #+#             */
/*   Updated: 2022/04/11 15:18:37 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	static int	bit;
	static int	count ;

	if (bit <= 7)
	{
		count <<= 1;
		if (signum == SIGUSR1)
			count ^= 1;
		++bit;
	}
	if (bit == 8)
	{
		write(1, &count, 1);
		if (!count)
			write(1, "\n", 1);
		count = 0;
		bit = 0;
	}
}

int	main(void)
{
	printf("%d\n", getpid());
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}	
