/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:01:45 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:19:26 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *node;

    if (!lst || !new)
        return ;
    
    if (!*lst)
    {
        *lst = new;
        return ;
    }

    node = *lst;
    while (node->next)
        node = node->next;
    node->next = new;
}