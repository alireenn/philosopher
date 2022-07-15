/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:20 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/15 12:24:48 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"


typedef struct s_philo
{
	int				id;
	int				n_eat;
	long long		hungry;
	int				end;
	struct s_rules	*rules;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	pthread_t		did_u_see;
}				t_philo;

typedef struct s_rules
{
	long long		n_ph;
	long long		time_death;
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
**		UTILS.C
*/
int			is_ok(int n);
int			ft_atoi(const char *str);
long long	what_time_is_it(void);
/*
**		INIT.C
*/
void		destroy(t_rules *rules);
void		init_philo(t_rules *rules);
int			mutex_init(t_rules *rules);
int			init(t_rules *rules, char *argv[]);
/*
**		START.C
*/
void		now_start_this(t_rules *rules);
void    	im_hungry(t_philo *philo);
void		*food(void *philo);
#endif