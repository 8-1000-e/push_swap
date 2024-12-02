/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:33:06 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/02 16:13:04 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sb(t_data *data)
{
	if (!sba(&data->stack_b))
		return (0);
	write(1, "sb\n", 3);
	return (1);
}

int rb(t_data *data)
{
	if (!rba(&data->stack_b))
		return (0);
	write(1, "rb\n", 3);
	return (1);
}

int rrb(t_data *data)
{
	if (!rrba(&data->stack_b))
		return (0);
	write(1, "rrb\n", 4);
}

int pb(t_data *data)
{
	pba(&data->stack_a, &data->stack_b);
	write(1, "pb\n",3);
	return (1);
}