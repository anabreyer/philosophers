/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:49:23 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/01/22 16:49:26 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_clear_memory(t_philo *philo, t_data *data)
{
	if (data && data->mutex)
		free (data->mutex);
	if (data)
		free (data);
	if (philo && philo->fork)
		free (philo->fork);
	if (philo)
		free (philo);
}

static int	ft_edgecases(int ac, char const *const *av)
{
	if ((ac == 6 && ft_atol (av[5]) == 0))
		return (TRUE);
	if (ft_atol (av[1]) == 0)
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char const *const *av)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (ft_check_args (ac, av) != SUCCESS)
		return ((void)ft_clear_memory (philo, data), EXIT_FAILURE);
	if (ft_edgecases (ac, av))
		return ((void)ft_clear_memory (philo, data), EXIT_SUCCESS);
	if (ft_init (&philo, &data, ac, av) != SUCCESS)
		return ((void)ft_clear_memory (philo, data), EXIT_FAILURE);
	if (ft_simulator (philo, data) != SUCCESS)
		return ((void)ft_clear_memory (philo, data), EXIT_FAILURE);
	return ((void)ft_clear_memory (philo, data), EXIT_SUCCESS);
}
