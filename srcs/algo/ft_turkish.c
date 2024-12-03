/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:45:20 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/03 02:08:10 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <limits.h>

// void	ft_draw_pile(t_data data)
// {
// 	t_list *stack_a = data.stack_a;
// 	t_list *stack_b = data.stack_b;

// 	ft_printf(1,"--- \t---\n A \t B\n--- \t---\n");
// 	while(stack_a || stack_b)
// 	{
// 		if (stack_a)
// 			ft_printf(1," %d", stack_a->content);
// 		if (stack_b)
// 			ft_printf(1,"\t %d \n",stack_b->content);
// 		else
// 			ft_printf(1,"\n");
// 		if (stack_a)
// 			stack_a = stack_a->next;
// 		if (stack_b)
// 			stack_b = stack_b->next;
// 	}
// }

int	ft_get_pos(t_list *stack, t_list *node)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp == node)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

t_list	*ft_get_big(t_list *stack)
{
	t_list	*tmp;
	t_list	*bigger;
	int		found;

	tmp = stack;
	found = INT_MIN;
	while (tmp)
	{
		if (tmp->content > found)
		{
			found = tmp->content;
			bigger = tmp;
		}
		tmp = tmp->next;
	}
	return (bigger);
}

t_op	ft_opti1(t_op all_op)
{
	if (all_op.ra == 0 || all_op.rb == 0)
		return (all_op);
	if (all_op.ra >= all_op.rb)
	{
		all_op.ra = all_op.ra - all_op.rb;
		all_op.rr = all_op.rb;
		all_op.rb = 0;
	}
	else
	{
		all_op.rb = all_op.rb - all_op.ra;
		all_op.rr = all_op.ra;
		all_op.ra = 0;
	}
	return (all_op);
}

t_op	ft_opti2(t_op all_op)
{
	if (all_op.rra == 0 || all_op.rrb == 0)
		return (all_op);
	if (all_op.rra >= all_op.rrb)
	{
		all_op.rra = all_op.rra - all_op.rrb;
		all_op.rrr = all_op.rrb;
		all_op.rrb = 0;
	}
	else
	{
		all_op.rrb = all_op.rrb - all_op.rra;
		all_op.rrr = all_op.rra;
		all_op.rra = 0;
	}
	return (all_op);
}

t_op	ft_opti_operations(t_op all_op, t_data *data)
{
	int		size_a;
	int		size_b;
	t_op	opt;

	opt = all_op;
	size_a = ft_lstsize(data->stack_a);
	size_b = ft_lstsize(data->stack_b);
	if (size_a > 0 && opt.ra > size_a / 2)
	{
		opt.rra = size_a - opt.ra;
		opt.ra = 0;
	}
	if (size_b > 0 && opt.rb > size_b / 2)
	{
		opt.rrb = size_b - opt.rb;
		opt.rb = 0;
	}
	opt = ft_opti1(opt);
	opt = ft_opti2(opt);
	return (opt);
}

int	ft_get_all_op(t_op *all_op)
{
	return (all_op->ra + all_op->rb + all_op->rr
		+ all_op->rra + all_op->rrb + all_op->rrr);
}

void	ft_start_operation(t_op *all_op, t_data *data, char type_stack)
{
	while (all_op->ra--)
		ra(data);
	while (all_op->rb--)
		rb(data);
	while (all_op->rr--)
		rr(data);
	while (all_op->rra--)
		rra(data);
	while (all_op->rrb--)
		rrb(data);
	while (all_op->rrr--)
		rrr(data);
	*all_op = (t_op){0, 0, 0, 0, 0, 0};
	if (type_stack == 'a')
		pb(data);
	else
		pa(data);
}

t_list	*ft_get_min(t_list *stack)
{
	t_list	*tmp;
	t_list	*min;

	min = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*ft_get_bigger(int content, t_list *stack)
{
	t_list	*tmp;
	t_list	*big;
	int		found;

	tmp = stack;
	found = INT_MAX;
	big = 0;
	while (tmp)
	{
		if (tmp->content > content && tmp->content < found)
		{
			found = tmp->content;
			big = tmp;
		}
		tmp = tmp->next;
	}
	if (!big)
		return (ft_get_min(stack));
	return (big);
}

t_list	*ft_get_smaller(int content, t_list *stack)
{
	t_list	*tmp;
	t_list	*small;
	int		found;

	tmp = stack;
	small = 0;
	found = INT_MIN;
	while (tmp)
	{
		if (tmp->content < content && tmp->content > found)
		{
			found = tmp->content;
			small = tmp;
		}
		tmp = tmp->next;
	}
	if (!small)
		return (ft_get_big(stack));
	return (small);
}

t_op	ft_get_best_op(t_data *data, t_list *tmp, t_list *stack1,
		t_list *stack2)
{
	t_op	tmp_op;

	tmp_op = (t_op){0, 0, 0, 0, 0, 0};
	tmp_op.ra = ft_get_pos(stack1, tmp);
	tmp_op.rb = ft_get_pos(stack2, ft_get_smaller(tmp->content, stack2));
	tmp_op = ft_opti_operations(tmp_op, data);
	return (tmp_op);
}

void	ft_pushb(t_data *data)
{
	t_op	opt;
	int		size;
	t_list	*min_node;

	ft_quicksort(data);
	opt = (t_op){0, 0, 0, 0, 0, 0};
	while (ft_lstsize(data->stack_b))
	{
		opt.ra = ft_get_pos(data->stack_a, ft_get_bigger(data->stack_b->content,
					data->stack_a));
		ft_start_operation(&opt, data, 'b');
	}
	min_node = ft_get_min(data->stack_a);
	if (ft_get_pos(data->stack_a, min_node) > ft_lstsize(data->stack_a) / 2)
		size = 1;
	else
		size = 0;
	while (data->stack_a != min_node)
	{
		if (size)
			rra(data);
		else
			ra(data);
	}
}

void	ft_turkish_sort(t_data *data)
{
	t_list	*tmp;
	t_op	all_op;
	t_op	tmp_op;
	int		min_ops;

	pb(data);
	pb(data);
	while (ft_lstsize(data->stack_a) > 3)
	{
		tmp = data->stack_a;
		min_ops = INT_MAX;
		all_op = (t_op){0, 0, 0, 0, 0, 0};
		while (tmp)
		{
			tmp_op = ft_get_best_op(data, tmp, data->stack_a, data->stack_b);
			if (ft_get_all_op(&tmp_op) < min_ops)
			{
				min_ops = ft_get_all_op(&tmp_op);
				all_op = tmp_op;
			}
			tmp = tmp->next;
		}
		ft_start_operation(&all_op, data, 'a');
	}
	ft_pushb(data);
}
