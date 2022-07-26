/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:22:53 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/26 17:04:24 by anovelli         ###   ########.fr       */
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
	sem_t			end;
	pthread_t		death;
	struct s_rules	*rules;
}				t_philo;

typedef struct s_rules
{
	int			n_ph;
	int			n_eat;
	int			die;
	long long	time_to_die;
	long long	start;
	long long	time_eat;
	long long	time_sleep;
	sem_t		*fork;
	sem_t		*mess;
	sem_t		*must_eat;
	sem_t		*dead;
	pthread_t	finish_eat;
	t_philo		*philo;
}				t_rules;

 /*
 **	init.c
 */
int			init(t_rules *rules, char *argv[], int argc);
void		init_philo(t_rules *rules);
sem_t		*sem_in(char *message, int n);
int			initrules(t_rules *rules);
 /*
 **	utils.c
 */
int			ft_check(int argc, char **argv);
int			is_digit_or_space(char c);
int			ft_atoi(const char *str);
long long	what_time_is_it(void);
void		now_start_this(t_rules *rules);
/*
**	start.c
*/
void		*all_soreta_things(void *philo);
void		*monitor(void *philo);
void		now_start_this(t_rules *rules);
void		*eat63(void	*rul);
/*
**  talk.c
*/
void		ft_tell_me(t_philo *philo, int id, char *str);
void		pezzott_sleep(long long time);
#endif