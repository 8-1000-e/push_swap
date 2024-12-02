/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:01:51 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 16:53:19 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "lib/printf/ft_printf.h"
#include "lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b; 
}				t_data;

t_list *get_stack(char *str);
void    clean_exit(t_list *a, int error);
t_list	*list_join(t_list *lst, t_list *lst2);
void    ft_clearlst(t_list *a);
void    check_args(int ac, char **av);
void	check_for_dups(t_list *lst);
void    start_sort(t_list *lst);
int	sa(t_data *data);
int	ra(t_data *data);
int rra(t_data *data);
int pa(t_data *data);
int sb(t_data *data);
int rb(t_data *data);
int rrb(t_data *data);
int pb(t_data *data);
int rba(t_list **stack);
int sba(t_list **stack);
int rrba(t_list **stack);
int pba(t_list **stack_1, t_list **stack_2);
void ss(t_data *data);
void rr(t_data *data);
void rrr(t_data *data);


#endif 