/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 00:00:00 by you               #+#    #+#             */
/*   Updated: 2025/10/28 00:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"

void	send_bit(pid_t server_pid, int bit, int *ack_flag)
{
	if (bit)
		kill(server_pid, SIGUSR2);
	else
		kill(server_pid, SIGUSR1);
	while (!*ack_flag)
		pause();
	*ack_flag = 0;
}

void	send_char(pid_t server_pid, char c, int *ack_flag)
{
	int	bit_position;

	bit_position = 7;
	while (bit_position >= 0)
	{
		send_bit(server_pid, (c >> bit_position) & 1, ack_flag);
		bit_position--;
	}
}

void	send_string(pid_t server_pid, char *str, int *ack_flag)
{
	while (*str)
	{
		send_char(server_pid, *str, ack_flag);
		str++;
	}
	send_char(server_pid, '\0', ack_flag);
}

int		ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}


