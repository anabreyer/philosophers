/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:44:41 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/01/22 16:44:42 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long	ft_abs_time(void)
{
	struct timeval	time;
	unsigned long	s;
	unsigned long	u;

	if (gettimeofday (&time, NULL) == -1)
		write (2, "Error: GETTIMEOFDAY(2)\n", 23);
	s = time.tv_sec * 1000;
	u = time.tv_usec / 1000;
	return (s + u);
}

unsigned long	ft_rel_time(unsigned long begin)
{
	unsigned long	abs_time;

	abs_time = ft_abs_time ();
	return (abs_time - begin);
}

void	ft_msleep(unsigned long msec)
{
	usleep (msec * 1000);
}
