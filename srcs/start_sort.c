/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:45 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/10 16:51:56 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    check_sort(t_list *lst)
{
    t_list *save_lst;

    save_lst = lst;
    while (lst->next && lst->next->content > lst->content)
        lst = lst->next;
    if (!lst->next)
        clean_exit(save_lst, 0);
    lst = save_lst;
}

void    start_sort(t_list *lst)
{
    t_data data;

    data.stack_a = lst;
    data.stack_b = 0;
    check_sort(lst);
    if (ft_lstsize(data.stack_a) <= 3)
        ft_quicksort(&data);
    else if (ft_lstsize(data.stack_a) == 4)
        ft_quicksort_four(&data);
    else if (ft_lstsize(data.stack_a) == 5)
        ft_quisort_five(&data);
    	// print_lst(data.stack_a);
    check_sort(lst);
    
    ft_turkish_sort(&data);
    ft_clearlst(lst);
}
