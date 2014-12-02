/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:14:25 by ccrapat           #+#    #+#             */
/*   Updated: 2014/12/02 07:04:49 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main_ls.h>
#include <libft.h>

static int		ft_check_all_args(int ac, char **av)
{
	int		flags;
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			flags = ft_check_args(av[i]);
			if (av[i][0] != '-')
				break ;
			i++;
		}
	}
	return (flags);
}

int				main(int ac, char **av)
{
	int		flags;

	flags = ft_check_all_args(ac, av);
	ft_create_lst(flags);
	return (0);
}
