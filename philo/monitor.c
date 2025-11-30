/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:30:14 by jiyawang          #+#    #+#             */
/*   Updated: 2025/11/30 17:42:30 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_status(t_philo *philo, char *status)
{
	size_t	timestamp;

	pthread_mutex_lock(philo->print_lock);
	timestamp = get_time_in_ms() - philo->start_time;
	if (!*(philo->dead))
		printf("%zu %d %s\n", timestamp, philo->ph_id + 1, status);
	pthread_mutex_unlock(philo->print_lock);
}

int	philosophers_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_time_lock);
	if (get_time_in_ms() - philo->last_meal_time > time_to_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_time_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_time_lock);
	return (0);
}
