/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:07:59 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/20 09:08:02 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

static int	g_first = 1;

typedef struct s_stock_str
{
	char	*key;
	char	*value;
}	t_stock_str;

t_stock_str	*dict_parse(const char *content, int *out_n);

int			ft_str_is_numeric(char *str);
int			ft_str_is_alpha(char *str);
int			ft_puterror(char *str);
int			ft_putstr(char *str);
int			ftstrlen(char *str);

int			ft_exist_file(char *name);
char		*ft_file_to_str(const char *name);

void		dict_free(t_stock_str *arr, int n);
void		free_until(t_stock_str *a, int n);
int			is_space(char c);
int			line_len(const char *p);
int			find_colon(const char *b, int len);

char		*dup_trim(const char *b, int len);

void		print_number_words(t_stock_str *dict, int n, char *nb);

int			my_strlen(const char *s);
void		puts1(const char *s);
void		put_space(int *first);
int			str_eq(const char *a, const char *b);
int			is_digit(char c);

char		*lookup(t_stock_str *dict, int n, const char *key);
void		put_key_word(t_stock_str *d, int n, const char *key, int *first);
void		u32_to_dec(int v, char *buf);
void		print_0_99(t_stock_str *d, int n, int v, int *first);
void		print_0_999(t_stock_str *d, int n, int v, int *first);

int			group_value(const char *nb, int len, int grp);
int			count_groups(const char *nb, int len);

#endif
