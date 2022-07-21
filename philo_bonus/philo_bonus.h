/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:22:53 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/21 16:22:03 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				n_eat;
	long long		now_die;
	int				end;
	pthread_t		process;
	struct s_rules	*rules;
}				t_philo;

typedef struct s_rules
{
	int				n_ph;
	long long		time_to_die;
	long long		time_eat;
	long long		time_sleep;
	long long		must_eat;
	long long		start;
	int				die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	must_eat_mutex;
	pthread_mutex_t	philo_time;
	t_philo			*philo;
}				t_rules;
 /*
 **	init.c
 */
int			init(t_rules *rules, char *argv[]);
 /*
 **	utils.c
 */
int			is_ok(int n);
int			ft_atoi(const char *str);
long long	what_time_is_it(void);
void		now_start_this(t_rules *rules);
#endif