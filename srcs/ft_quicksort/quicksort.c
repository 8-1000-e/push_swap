/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:46:43 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 21:29:57 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_quicksort(t_data data)
{
	while (1)
	{
	if (data.stack_a->content > ft_lstlast(data.stack_a)->content)
		ra(&data);
	if (data.stack_a->content > data.stack_a->next->content)
		sa(&data);
	check_sort(data.stack_a);
	}
}