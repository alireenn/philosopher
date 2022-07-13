/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evento <evento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:09 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/13 15:41:20 by evento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_and_init(int argc, char **argv, t_rules *rules)
{
	int	i;

	i = 0;
	while (i <= argc)
	{
		if (argv[i] > __INT_MAX__ || argv[i] < 0)
			return (0);
		i++;
	}
	if (ft_mutex_init(rules) == 0)
		return (0                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      );
	rules->philo = (t_philo *) malloc (sizeof(t_philo) * rules->n_ph);
	if (rules->philo == NULL)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules	*rules;

	if (argc != 5 && argc != 6)
		return (printf("Wrong amount of arguments\n"));
	if (!check_and_init(argc, argv, rules))
		return (printf("wrong arguments\n"));

}
