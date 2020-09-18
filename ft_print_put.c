/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:19:42 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/18 16:38:06 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_printstr(char *str, int max)
{
	int i;

	i = 0;
	while (str[i] && i < max)
		ft_printchar(str[i++]);
	return (i);
}

int ft_printhex(unsigned int nb, char value)
{
	char s[8];
	char *hex;
	int i;
	int print;

	i = 0;
	if (value == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	while (nb)
	{
		s[i] = (nb % 16);
		nb /= 16;
		i++;
	}
	print = i;
	while (--i >= 0)
		ft_printchar(hex[s[i]]);
	return (print);
}

int	ft_printaddr(unsigned long addr_l)
{
	char				aff[20];
	int					i;
	int print;

	i = 0;
	while (addr_l)
	{
		if ((addr_l % 16) < 10)
			aff[i] = (addr_l % 16) + '0';
		else
			aff[i] = (addr_l % 16) + 87;
		addr_l /= 16;
		i++;
	}
	print = i;
	while (--i >= 0)
		ft_putchar_fd(aff[i], 1);
	return (print);
}
