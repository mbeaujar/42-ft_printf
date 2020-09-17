/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:33:50 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/17 23:10:41 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_select_type(const char *s, int *i, va_list args)
{
	t_flags flags;
	int print;

	ft_set_flags(s, i, &flags, args);
	if (s[*i] == 'c')
		print = ft_print_char();
	else if (s[*i] == 's')
		print = ft_print_string();
	else if (s[*i] == 'p')
		print = ft_print_address();
	else if(s[*i] == 'd' || s[*i] == 'i')
		print = ft_print_nbr();
	else if(s[*i] == 'u')
		print = ft_print_nbr();
	else if (s[*i] == 'x' || s[*i] == 'X')
		print = ft_print_hex();
	else if (s[*i] == '%')
		print = ft_print_percent(flags);
	else
		print = ft_print_no_type();
	if (s[*i])
		*i++;
	return (print);
}

int ft_printf(const char *format, ...)
{
	int print;
	int i;
	va_list args;

	va_start(args, format);
	i = 0;
	print = 0;
	while (format[i++])
	{
		if (format[i])
			print += ft_select_type(format, ++i, args);
		else
			print += ft_printchar(format[i]);
	}
	va_end(args);
	return (print);
}
