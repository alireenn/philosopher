/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:09 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/29 14:34:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
/*
**		OGNI TANTO VA MALE IL SALVATAGGIO DEL TEMPO
*/
int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		return (printf("Wrong amount of arguments\n"));
	if (!init(&rules, argv, argc))
		return (printf("wrong arguments\n"));
	if (ft_atoi(argv[1]) == 1)
	{
		printf("%lld %d %s\n", rules.start, rules.philo->id, FORK);
		printf("%d %d %s\n", ft_atoi(argv[2]) + 1, rules.philo->id, DIED);
		destroy(&rules);
		return (0);
	}
	if (argc == 6)
	{
		rules.must_eat = ft_atoi(argv[5]);
		if (rules.must_eat <= 0)
			return (printf("Something is bad... \
			Try again with other parameters\n"));
	}
	else
		rules.must_eat = -1;
	now_start_this(&rules);
}
