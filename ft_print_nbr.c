/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 23:18:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/20 18:06:56 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ft_treat_nbr(long long nb, int *print, t_flags *flags, int *sign)
{
	unsigned int nbr;

	if (nb < 0 /*&& (flags->dot >= 0 || flags->zero == '0')*/)
	{
		*sign = 1;
		if (flags->zero == '0' && flags->dot == -1)
		{
			ft_printchar('-');
			*sign = 0;
		}
		nbr = -nb;
		flags->width--;
		(*print)++;
	}
	else
		nbr = nb;
	return (nbr);
}


void ft_putnbr(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_printchar(nbr + '0');
}

int ft_printnbr(unsigned int nbr)
{
	int print;

	print = ft_len_nbr(nbr);
	ft_putnbr(nbr);
	return (print);
}


int ft_print_nbr_dot(unsigned int nbr, t_flags flags, int sign)
{
	int print;

	print = 0;
	if (sign == 1)
		ft_printchar('-');
	if (flags.dot >= 0)
		print += ft_print(flags.dot, ft_len_nbr(nbr), '0');
	print += ft_printnbr(nbr);
	return (print);
}

int ft_print_nbr_width(unsigned int nbr, t_flags flags, int sign)
{
	int print;

	print = 0;
	if (flags.less == 1)
		print += ft_print_nbr_dot(nbr, flags, sign);
	if (flags.dot >= 0 && (flags.dot < ft_len_nbr(nbr)))
		flags.dot = ft_len_nbr(nbr);
	if (flags.dot >= 0)
		print += ft_print(flags.width, flags.dot, ' ');
	else
		print += ft_print(flags.width, ft_len_nbr(nbr), flags.zero);
	if (flags.less == 0)
		print += ft_print_nbr_dot(nbr, flags, sign);
	return (print);
}

int ft_print_nbr(long long nb, t_flags flags)
{
	unsigned int nbr;
	int print;
	int sign;

	print = 0;
	sign = 0;
	if (flags.dot == 0 &&  nb == 0)
		return (ft_print(flags.width, 0, ' '));
	nbr = ft_treat_nbr(nb, &print, &flags, &sign);
	print += ft_print_nbr_width(nbr, flags, sign);
	return (print);
}
