/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:12:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/30 20:05:09 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_lst(t_list *a)
{
	while (a)
	{
		ft_printf(1, "%d\n", a->content);
		a = a->next;
	}
}

int main(int ac, char **av)
{
	t_list *a;
	t_list *a_new;
	int c_ac;

	a = NULL;
	av++;
	c_ac = ac;
	check_args(ac, av);
	while (--c_ac)
	{
		a_new = get_stack(*av);
		if (!a_new)
			clean_exit(a);
		a = list_join(a, a_new);
		av++;
	}
	check_for_dups(a);
	print_lst(a);
	ft_clearlst(a);
}
