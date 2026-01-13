/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:44:16 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/17 19:17:00 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(va_list args);
int	search_type(const char i, va_list args);
int	ft_putchar(char c);
int	ft_putnbr_base(unsigned int nb, char *base, int count);
int	ft_puthex(unsigned long nb, char *base);
int	ft_putnbr_unsigned(unsigned int nb, int count);
int	ft_putnbr(int nb);
int	ft_put_ptr(void *ptr);

#endif
