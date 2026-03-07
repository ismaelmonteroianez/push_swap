/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:32:15 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 17:37:40 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printnbr(int nbr)
{
	char	a;
	int		n;

	n = 0;
	if (nbr < 0)
	{
		write(2, "-", 1);
		nbr = nbr * -1;
		n++;
	}
	if (nbr >= 10)
	{
		n = n + ft_printnbr(nbr / 10);
		a = nbr % 10 + '0';
		write(2, &a, 1);
		n++;
		return (n);
	}
	a = nbr + 48;
	write(2, &a, 1);
	n++;
	return (n);
}
