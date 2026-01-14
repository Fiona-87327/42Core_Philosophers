/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aktion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:30:40 by jiyawang          #+#    #+#             */
/*   Updated: 2026/01/14 12:31:35 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_action(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	think_action(t_philo *philo)
{
	print_action(philo, "is thinking");
}

static void	take_forks(t_philo *philo)
{
	if (philo->ph_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
}

void	eat_action(t_philo *philo)
{
	if (philo->number_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	take_forks(philo);
	pthread_mutex_lock(philo->meal_time_lock);
	philo->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(philo->meal_time_lock);
	print_action(philo, "is eating");
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->meal_time_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_time_lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	die_action(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	*(philo->dead) = 1;
	pthread_mutex_unlock(philo->dead_lock);
}
