/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:45:20 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/02 19:58:55 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"



void ft_draw_pile(t_data data)
{

	t_list *stack_a = data.stack_a;
	t_list *stack_b = data.stack_b;

	ft_printf(1,"--- \t---\n A \t B\n--- \t---\n");
	while(stack_a || stack_b)
	{
		if (stack_a)
			ft_printf(1," %d", stack_a->content);
		if (stack_b)
			ft_printf(1,"\t %d \n",stack_b->content);
		else
			ft_printf(1,"\n");
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	
}

int ft_get_pos(t_list *stack,  t_list *node)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = stack;
	while(tmp)
	{
		if (tmp == node)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

t_list *ft_get_bigger(t_list *stack)
{
	t_list *tmp;
	t_list *bigger;

	tmp = stack;
	bigger = tmp;
	while(tmp)
	{
		if (tmp->content > bigger->content)
			bigger = tmp;
		tmp = tmp->next;
	}
	return (bigger);
}

t_list *ft_get_smaller(int content , t_list *stack)
{
	t_list *tmp;
	t_list *small;

	tmp = stack;
	while(tmp)
	{
		if ((!small || tmp->content > small->content) && tmp->content < content)
			small = tmp;
		tmp = tmp->next;
	}
	if (!small)
		return (ft_get_bigger(stack));
	return (small);
}

void ft_turkish_sort(t_data *data)
{

	t_list *tmp;
	int i;
	pb(data);
	pb(data);
	tmp = data->stack_a;
	ft_draw_pile(*data);
	while(tmp)
	{
		i = ft_get_pos(data->stack_a,tmp);
		ft_printf(1,"%d   ",i);
		ft_printf(1,"%d   ",ft_get_pos(data->stack_b, ft_get_smaller(tmp->content,data->stack_b)));
		i = i + ft_get_pos(data->stack_b, ft_get_smaller(tmp->content,data->stack_b)) + 1;
		ft_printf(1,"content : %d \tcoup: %d \t smaller: %d\n",tmp->content, i, ft_get_smaller(tmp->content,data->stack_b)->content);
		tmp = tmp->next;
	}
}