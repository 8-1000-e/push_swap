/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_shared.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:17:28 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/02 16:13:04 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int rrr(t_data *data)
{
	rrba(&data->stack_b);
	rrba(&data->stack_a);
	write(1, "rrr\n",4);
}

int rr(t_data *data)
{
	rba(&data->stack_a);
	rba(&data->stack_b);
	write(1, "rr\n",3);
}

int ss(t_data *data)
{
	sba(&data->stack_a);
	sba(&data->stack_b);
	write(1, "ss\n",3);
}
