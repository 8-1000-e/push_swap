/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:45 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 19:27:01 by npalissi         ###   ########.fr       */
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
    // (void)data;
    // turkish_sort(data);    
   
    ft_turkish_sort(&data);
    ft_clearlst(lst);
}
