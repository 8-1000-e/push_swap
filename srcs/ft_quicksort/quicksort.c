/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:46:43 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/10 16:57:19 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_quicksort(t_data *data)
{
	if (data->stack_a->content > data->stack_a->next->content)
		sa(data);
	if (data->stack_a->content > ft_lstlast(data->stack_a)->content)
		rra(data);
	if (data->stack_a->next->content > ft_lstlast(data->stack_a)->content)
	{
		ra(data);
		sa(data);
		rra(data);
	}
}
