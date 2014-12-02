/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:29:17 by ccrapat           #+#    #+#             */
/*   Updated: 2014/12/02 07:47:27 by ccrapat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_LS_H
# define MAIN_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <stdlib.h>

# define FLAG_R 1
# define FLAG_r 2
# define FLAG_a 4
# define FLAG_t 8
# define FLAG_l 16

typedef struct		s_data
{
	char			*file;
	struct s_data	*prev;
	struct s_data	*next;
}					t_data;

int		ft_check_args(char *av);
void		ft_create_lst(int flags);

#endif
