/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:12:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 20:31:44 by npalissi         ###   ########.fr       */
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
			clean_exit(a, 1);
		a = list_join(a, a_new);
		av++;
	}
	check_for_dups(a);
	start_sort(a);
}
