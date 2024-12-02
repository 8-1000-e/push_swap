/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:01:51 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 16:14:29 by npalissi         ###   ########.fr       */
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

#endif 