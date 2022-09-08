/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:22:53 by anovelli          #+#    #+#             */
/*   Updated: 2022/08/11 13:35:18 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <stdio.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

typedef struct s_philo
{
	int				id;
	int				n_eat;
	long long		last_eat;
	pid_t			pid;
	pthread_t		death;
	struct s_rules	*rules;
}				t_philo;

typedef struct s_rules
{
	long long	time_to_die;
	long long	start;
	long long	time_eat;
	long long	time_sleep;
	int			n_to_eat;
	int			n_ph;
	sem_t		*fork;
	sem_t		*mess;
	sem_t		*must_eat;
	sem_t		*dead;
	t_philo		*philo;
	pthread_t	finish_eat;
}				t_rules;

/*
**	init.c
*/
void		init_philo(t_rules *rules);
int			init(t_rules *rules, char *argv[], int argc);
sem_t		*sem_in(char *message, int n);
int			initrules(t_rules *rules, int argc, char **argv);
/*
**	utils.c
*/
int			ft_check(int argc, char **argv);
int			ft_atoi(const char *str);
int			is_digit_or_space(char c);
long long	what_time_is_it(void);
void		pezzott_sleep(long long time);
/*
**	start.c
*/
int			finish(t_philo *philo);
void		now_start_this(t_rules *rules);
void		*all_soreta_things(void *philo);
void		*monitor(void *philo);
void		*eat63(void	*rul);
/*
**	utils2.c
*/
void		ft_tell_me(t_philo *philo, int id, char *str);
int			is_one(t_rules *rules);
void		ft_tell_me_die(t_philo *philo, int id, char *str);
#endif