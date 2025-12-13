/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:03:10 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:21:53 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_lstsize(t_list *lst)
{
    t_list *node;
    int count;

    count = 0;
    node = lst;
    while (node)
    {
        count++;
        node = node->next;
    }
    return (count);
}
