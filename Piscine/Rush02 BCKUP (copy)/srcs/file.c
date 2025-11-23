/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:07:27 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/20 09:07:30 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_existe_file(char *name)
{
	int	f;

	f = open(name, O_RDONLY);
	if (f == -1)
		return (0);
	close(f);
	return (1);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static char	*ft_join_and_free(char *acc, const char *buf, ssize_t nread)
{
	size_t	len1;
	char	*res;

	res = 0;
	len1 = ft_strlen(acc);
	res = (char *)malloc(len1 + (size_t)nread + 1);
	if (!res)
	{
		free(acc);
		return (NULL);
	}
	if (acc)
		ft_memcpy(res, acc, len1);
	ft_memcpy(res + len1, buf, (size_t)nread);
	res[len1 + (size_t)nread] = '\0';
	free(acc);
	return (res);
}

char	*ft_file_to_str(const char *name)
{
	int		fd;
	ssize_t	nread;
	char	buf[4096];
	char	*acc;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	acc = NULL;
	nread = -1;
	while (nread != 0)
	{
		nread = read(fd, buf, sizeof(buf));
		acc = ft_join_and_free(acc, buf, nread);
		if (!acc)
		{
			close(fd);
			return (NULL);
		}
	}
	if (close(fd) < 0 || nread < 0)
		free(acc);
	return (acc);
}
