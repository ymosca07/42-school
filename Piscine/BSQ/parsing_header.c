/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paring_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:39:26 by adarolla          #+#    #+#             */
/*   Updated: 2025/09/23 11:39:26 by adarolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	parse_header(char *col, char *full, char *setback, char *naught)
{
	int 	length;
	char 	varbuffer [4096];
	int 	limitsmax;
	char	*line;

	length = ft_strlen(line);
	*full = line[length - 1];
	*setback = line[length - 2];
	*naught = line[length - 3];
	limitsmax = *full;
	if(length < 5)
		write (2, "map error\n", 10);
	if (line >= varbuffer)
		write (2, "map error\n", 10);
	ft_strncpy(full, line, limitsmax);
	*col = ft_atoi(varbuffer);
	if (*col <= 0)
		write (1, "map error\n", 1);
	if (*naught == *full || *naught == *setback || *full == *naught)
		return (0);
	return(1);
}
int main(void)
{
	char col[50] = "9";
	char full[50] = "x";
	char setback[50] = "o";
	char naught[50] = ".";
	int rse = parse_header(col,full, setback, naught);
	printf("%d\n", rse);
}
