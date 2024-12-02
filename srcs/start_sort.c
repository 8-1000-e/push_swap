/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:45 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/02 19:44:36 by edubois-         ###   ########.fr       */
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
    if (ft_lstsize(data.stack_a) < 4)
        ft_quicksort(data);
    // turkish_sort(data);   
    ft_clearlst(lst);
}
