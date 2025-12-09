/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:32:20 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/26 17:32:20 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *str_capitalize(char *str)
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || i == 0))
			str[i] -= 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && str[i - 1] != ' ')
			str[i] += 32;
		i++;
	}
	return (str);
}
int main(int argc, char **argv)
{
	(void)argc;
	printf("%s", str_capitalize(argv[1]));
}
