/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:17:30 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/24 17:24:12 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_count_len(char **input)
{
    int count;
    int n;

    n = 1;
    count = 0;
    while (input[n])
    {
        count += ft_strlen(input[n]);
        if (input[n + 1])
            count += 1;
        n++;
    }
    return (count);
}
