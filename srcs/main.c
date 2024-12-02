/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:12:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 20:35:45 by edubois-         ###   ########.fr       */
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

	if (ac != 1)
	{
		a = NULL;
		av++;
		check_args(ac, av);
		while (--ac)
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
}

