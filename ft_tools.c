/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:26:52 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/20 19:33:25 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_int(long n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		return (0);
	}
	else
		return (1);
}
int	ft_check_order(int *numbers, int numbers_size)
{
	int i;

	i = 0;
	while(i < numbers_size - 1)
	{
		if(numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
