/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:01:51 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/30 19:55:54 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "lib/printf/ft_printf.h"
#include "lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

t_list *get_stack(char *str);
void    clean_exit(t_list *a);
t_list	*list_join(t_list *lst, t_list *lst2);
void    ft_clearlst(t_list *a);
void    check_args(int ac, char **av);
void	check_for_dups(t_list *lst);

#endif 