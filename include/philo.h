/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:44:50 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/01/22 16:47:56 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_mutexes
{
	PRINT,
	MEALS,
	DONE,
	DIED,
	M_NUM
}	t_mutexes;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef struct s_data
{
	int				philo_nb;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				time_thk;
	int				must_eat;
	unsigned long	simbegin;
	int				done;
	int				dies;
	pthread_mutex_t	*mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	unsigned long	last_meal;
	int				meal_counter;
	int				lfork;
	int				rfork;
	pthread_mutex_t	*fork;
	t_data			*data;
}	t_philo;

//UTILS.C
long			ft_atol(char const *str);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

//CHECKARGS.C
int				ft_check_args(int ac, char const *const *av);

//TIME_UTILS.C
unsigned long	ft_abs_time(void);
unsigned long	ft_rel_time(unsigned long begin);
void			ft_msleep(unsigned long msec);

//SIM_UTILS.C
void			ft_print(t_philo *philo, char const *const a);
void			ft_died(t_data *data);
void			ft_done(t_data *data);
int				ft_check_died(t_philo *philo);
int				ft_check_done(t_philo *philo);

//SIMULATOR.C
int				ft_simulator(t_philo *philo, t_data *data);

//SIMULATION.C
void			*ft_simulation(void *arg);

//INIT.C
int				ft_init_philo(t_philo **philo, t_data *data);
int				ft_init_data_mutexes(t_data **data);
int				ft_init_data(t_data **data, int ac, char const *const *av);
int				ft_init(t_philo **philo, t_data **data,
					int ac, char const *const *av);

#endif