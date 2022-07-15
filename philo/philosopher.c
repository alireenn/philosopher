/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:09 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/15 11:12:52 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"



int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		return (printf("Wrong amount of arguments\n"));
	if (!init(&rules, argv))
		return (printf("wrong arguments\n"));
	init_philo(&rules);
	if (argc == 6)
	{
		rules.must_eat = ft_atoi(argv[5]);
		if (is_ok(rules.must_eat) == 0)
			return (printf("no fra, impara a scrivere porcoddio\n"));
	}
	else
		rules.must_eat = -1;
	now_start_this_shit(&rules);
}
