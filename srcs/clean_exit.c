/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:58:32 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/30 20:04:18 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_clearlst(t_list *a)
{
    t_list *save;

    while (a)
    {
        save = a->next;
        free(a);
        a = save;
    }
}

void    clean_exit(t_list *a)
{
    if (a)
        ft_clearlst(a);
    ft_printf(2, "Error \n");
    exit(0);
}