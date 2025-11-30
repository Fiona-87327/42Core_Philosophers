/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:10:50 by jiyawang          #+#    #+#             */
/*   Updated: 2025/11/30 15:28:40 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead))
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ph_id % 2 == 0)
		usleep(100);
	while (!dead_check(philo))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (arg);
}

int	thread_create(t_philo *philo, pthread_mutex_t *forks)
{
	pthread_t	*threads;
	int			i;

	if (pthread_create(&threads, NULL, &monitor, program->philos) != 0)
		dstroy_all(philo, forks);
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread_id, NULL, &philo_thread,
				&philo[i]) != 0)
			return (dstroy_all(philo, forks), 1);
		i++;
	}
	i = 0;
	if (pthread_join(threads, NULL) != 0)
		dstroy_all(philo, forks);
	while (i < philo->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			return (dstroy_all(philo, forks), 1);
		i++;
	}
	return (0);
}
