/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:55:42 by nnemeth           #+#    #+#             */
/*   Updated: 2022/06/10 12:54:49 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_text(int pid, char *text)
{
	int		i;
	int		c;

	i = -1;
	while (text[++i])
	{
		c = 8;
		while (--c >= 0)
		{	
			if ((text[i] >> c & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
	c = 8;
	while (--c >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(10);
	}
}

int	main(int argc, char *argv[])
{	
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (argc < 3)
	{
		ft_printf("You did not write any text");
		exit(1);
	}
	else if (!ft_isdigit(argv[1][i]))
	{
		ft_printf("The PID should only be numbers");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str = ft_strdup(argv[2]);
	send_text(pid, str);
	free(str);
	return (0);
}
