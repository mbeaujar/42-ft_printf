/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:53:05 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/18 18:49:28 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print(int start, int end, char c)
{
	int i;

	i = start;
	while (start - end > 0)
	{
		ft_printchar(c);
		start--;
	}
	return (i - end);
}


int ft_print_percent(t_flags flags)
{
	int print;

	print = 0;
	if (flags.less == 1)
		print += ft_printstr("%", 1);
	print += ft_print(flags.width, 1, flags.zero);
	if (flags.less == 0)
		print += ft_printstr("%", 1);
	return (print);
}
