/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:33:17 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/18 00:34:06 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_len_nbr(unsigned int nbr)
{
	int i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_len_hex(unsigned int nbr)
{
	int i;

	i = 0;
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
