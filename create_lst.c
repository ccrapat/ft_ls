/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 06:28:38 by ccrapat           #+#    #+#             */
/*   Updated: 2014/12/02 07:47:39 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main_ls.h>
#include <libft.h>

t_data		*ft_copy_data(t_data *lst, struct dirent *test)
{
	if (!lst)	
	{
		lst = (t_data *)malloc(sizeof(t_data));
		lst->file = test->d_name;
		lst->prev = NULL;
		lst->next = NULL;
		return (lst);
	}
	lst->next = (t_data *)malloc(sizeof(t_data));
	lst->next->prev = lst;
	lst->next->next = NULL;
	lst->next->file = test->d_name;
	return (lst->next);
}

void		ft_init_lst()
{
	DIR					*folder;
	struct dirent		*test;
	t_data				*lst;

	folder = opendir(".");
	lst = NULL;
	while ((test = readdir(folder)))
		lst = ft_copy_data(lst, test);
	while (lst->prev)
		lst = lst->prev;
	while (lst->next)
	{
		ft_putendl(lst->file);
		lst = lst->next;
	}
}

void		ft_create_lst(int flags)
{
	if ((flags | FLAG_R) == flags)
		ft_init_lst();	
}
