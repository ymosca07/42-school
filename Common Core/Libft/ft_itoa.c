/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:01:54 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/22 14:01:54 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	n_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_reverse(char *nb)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(nb) - 1;
	while (i < len)
	{
		tmp = nb[i];
		nb[i] = nb[len];
		nb[len] = tmp;
		i++;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	len;
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	len = n_len(n);
	i = 0;
	str = malloc((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[i++] = '0';
	while (nb > 0)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_reverse(str);
	return (str);
}
