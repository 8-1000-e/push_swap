/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:24:24 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/10 16:57:01 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_min_to_top(t_data *data)
{
	t_list	*min;
	int		pos;
	int		rotate;

	min = ft_get_min(data->stack_a);
	pos = ft_get_pos(data->stack_a, min);
	rotate = pos < ft_lstsize(data->stack_a) / 2;
	while (data->stack_a != min)
	{
		if (rotate)
			ra(data);
		else
			rra(data);
	}
}

void	ft_quicksort_four(t_data *data)
{
	ft_min_to_top(data);
	pb(data);
	ft_quicksort(data);
	pa(data);
}

void	ft_quisort_five(t_data *data)
{
	ft_min_to_top(data);
	pb(data);
	ft_min_to_top(data);
	pb(data);
	ft_quicksort(data);
	pa(data);
	pa(data);
}
