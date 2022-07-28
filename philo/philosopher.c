/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:52:09 by anovelli          #+#    #+#             */
/*   Updated: 2022/07/27 16:50:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		return (printf("Wrong amount of arguments\n"));
	if (!init(&rules, argv, argc))
		return (printf("wrong arguments\n"));
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
