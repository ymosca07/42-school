/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_skip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:29:06 by ymosca--          #+#    #+#             */
/*   Updated: 2025/12/13 01:53:22 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen_skip(const char *str)
{
	size_t	i;
    size_t count;

    count = 0;
	i = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        i++;
        count++;
    }
    
    while (str[i] == '0')
    {    
        i++;
    }
    
	while (str[i])
    {
		i++;
        count++;
    }
	return (count);
}
