/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:28:23 by jiyawang          #+#    #+#             */
/*   Updated: 2025/11/24 15:31:09 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void input_init(t_philo *philo, char **argv)
{
    philo->time_to_die = (size_t)ft_atoi(argv[2]);
    philo->time_to_eat = (size_t)ft_atoi(argv[3]);
    philo->time_to_sleep = (size_t)ft_atoi(argv[4]);
    philo->number_of_philosophers = ft_atoi(argv[1]);
    if (argv[5])
        philo->num_times_to_eat = ft_atoi(argv[5]);
    else
        philo->num_times_to_eat = -1;
}

