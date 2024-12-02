/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:35:38 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/30 20:19:40 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_for_letters(char **av, int ac)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (--ac && av[++j])
	{
		i = 0;
		while (av[j][i] && ft_strchr(" 0123456789-+", av[j][i]))
			i++;
		if (av[j][i])
		    clean_exit(NULL);
	}
	if (av[++j])
		clean_exit(NULL);
}

void	check_for_sign(char **av, int ac)
{
	int	i;
	int	j;
	
	i = 0;
	j = -1;
	while (--ac && av[++j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_issign(av[j][i]) && !ft_isdigit(av[j][i + 1]))
				clean_exit(NULL);
			i++;
		}
	}
	if (av[++j])
		clean_exit(NULL);
}

void	check_for_dups(t_list *lst)
{
	(void)lst;
}

void    check_args(int ac, char **av)
{
	check_for_letters(av, ac);
	check_for_sign(av, ac);
}
