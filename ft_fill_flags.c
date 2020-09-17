/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:59:38 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/17 22:32:37 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_flags_less(t_flags *flags)
{
	flags->zero = ' ';
	flags->less = 1;
}

void ft_flags_dot(const char *s, int *i, t_flags *flags, va_list args)
{
	if (s[*i] == '*')
		flags->dot = va_args(args, int);
	else
	{
		flags->dot = 0;
		while (ft_is_digit(s[*i]))
			flags->dot = (flags->dot * 10) + (s[*i++] - '0');
	}
}

void ft_flags_width(t_flags *flags, va_list args)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->less = 1;
		flags->width *= -1;
	}
}

void ft_flags_digit(const char *s, int *i, t_flags *flags)
{
	if (flags.star == 1)
		flags.width = 0;
	while (ft_is_digit(s[*i]))
		flags->width = (flags->width * 10) + (s[*i++] - '0');
}
