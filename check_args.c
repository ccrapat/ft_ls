/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 00:53:18 by ccrapat           #+#    #+#             */
/*   Updated: 2014/12/02 07:04:46 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main_ls.h>
#include <libft.h>

static void		ft_print_error(char *av)
{
	while (*av == '-')
		av++;
	ft_putstr("ft_ls: illegal option -- ");
	ft_putendl(av);
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(-1);
}

static int		ft_add_flags(char c)
{
	if (c == 'l')
		return (FLAG_l);
	else if (c == 'R')
		return (FLAG_R);
	else if (c == 'r')
		return (FLAG_r);
	else if (c == 't')
		return (FLAG_t);
	else if (c == 'a')
		return (FLAG_a);
	return (32);
}

int				ft_check_args(char *av)
{
	static int		flags;
	int				i;

	i = 0;
	while (av[i] == '-' && av[i] != '\0')
		i++;
	if ((i == 2 && av[i] == '\0') || i == 0)
		return (flags);
	else if (i == 2 && av[i] != '\0')
		ft_print_error(av);
	else if (i > 2)
		ft_print_error(av);
	while (av[i])
	{
		if ((flags = flags | ft_add_flags(av[i])) > 31)
			ft_print_error(av);
		i++;
	}
	return (flags);
}
