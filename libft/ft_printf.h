/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:30:56 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 17:03:27 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define FIRST_ASCII_CHAR	0
# define LAST_ASCII_CHAR	127
# define FIRST_PRINTABLE_CHAR	32
# define LAST_PRINTABLE_CHAR	126
# define DIFF_LOWER_UPPER		32
# define SPACE 32
# define FIRST_WHITESPACE 9
# define LAST_WHITESPACE 13

int	ft_printf(const char *format, ...);
int	ft_format_printf(char type, va_list args);

int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *str);
int	ft_putnbr_printf(int n);
int	ft_putnbr_unsigned_printf(unsigned int n);

int	putnbr_adress_printf(uintptr_t num);
int	ft_putnbr_ptr_printf(void *ptr);

int	ft_converthexa_printf(unsigned long num, char c);
int	ft_base16low_printf(unsigned long num);
int	ft_base16high_printf(unsigned long num);
int	ft_putrstr_printf(char *str);

#endif