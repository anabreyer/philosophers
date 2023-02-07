/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:49:34 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/01/22 16:49:38 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_start_eating(t_philo *self)
{
	pthread_mutex_lock (&self->fork[ft_min (self->lfork, self->rfork)]);
	ft_print (self, "has taken a fork");
	if (self->lfork == self->rfork)
	{
		pthread_mutex_unlock (&self->fork[ft_min (self->lfork, self->rfork)]);
		return (FAILURE);
	}
	pthread_mutex_lock (&self->fork[ft_max (self->lfork, self->rfork)]);
	ft_print (self, "has taken a fork");
	ft_print (self, "is eating");
	return (SUCCESS);
}

static int	ft_finish_eating(t_philo *self)
{
	ft_print (self, "is sleeping");
	pthread_mutex_unlock (&self->fork[ft_max (self->lfork, self->rfork)]);
	pthread_mutex_unlock (&self->fork[ft_min (self->lfork, self->rfork)]);
	ft_msleep(self->data->time_slp);
	return (SUCCESS);
}

static int	ft_eating(t_philo *self)
{
	if (ft_start_eating (self) != SUCCESS)
		return (FAILURE);
	pthread_mutex_lock (&self->data->mutex[MEALS]);
	self->last_meal = ft_abs_time ();
	self->meal_counter++;
	pthread_mutex_unlock (&self->data->mutex[MEALS]);
	if (ft_check_done (self))
	{
		ft_finish_eating (self);
		return (FAILURE);
	}
	ft_msleep(self->data->time_eat);
	ft_finish_eating (self);
	return (SUCCESS);
}

void	*ft_simulation(void *arg)
{
	t_philo	*self;

	self = (t_philo *) arg;
	if (self->id % 2 == 0)
	{
		ft_print (self, "is thinking");
		ft_msleep(self->data->time_eat);
	}
	while (1)
	{
		if (ft_check_died(self))
			break ;
		if (ft_eating (self) != SUCCESS)
			break ;
		ft_print (self, "is thinking");
		ft_msleep(self->data->time_thk);
	}
	return (NULL);
}
