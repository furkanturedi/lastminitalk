/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 00:00:00 by you               #+#    #+#             */
/*   Updated: 2025/10/28 00:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <sys/types.h>

void	send_bit(pid_t server_pid, int bit, int *ack_flag);
void	send_char(pid_t server_pid, char c, int *ack_flag);
void	send_string(pid_t server_pid, char *str, int *ack_flag);
int		ft_atoi(const char *str);

#endif


