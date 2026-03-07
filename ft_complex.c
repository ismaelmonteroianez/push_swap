/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:40:17 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 13:25:07 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
bigger >> bits es un desplazamiento a la derecha (right shift).

Desplaza los bits de bigger bits posiciones hacia la derecha.

Ejemplo: si bigger = 5 (101):

bits = 0 → 5 >> 0 = 101 → no es 0 → entra al bucle

bits = 1 → 5 >> 1 = 10 → no es 0 → entra al bucle

bits = 2 → 5 >> 2 = 1 → no es 0 → entra al bucle

bits = 3 → 5 >> 3 = 0 → sale del bucle
*/
int	ft_get_max_bits(int bigger)
{
	int	bits;

	bits = 0;
	while ((bigger >> bits) != 0)
		bits++;
	return (bits);
}

int	ft_get_max_number(t_list **a)
{
	t_list	*tmp;
	t_list	*bigger;

	bigger = *a;
	tmp = (*a)->next;
	while (tmp != NULL)
	{
		if (bigger->index < tmp->index)
			bigger = tmp;
		tmp = tmp->next;
	}
	return (bigger->index);
}

void	ft_radix_sort(t_list **a, t_list **b, int max_bits)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(*a);
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while ((*b) != NULL)
			pa(a, b);
		i++;
	}
	return ;
}

int ft_complex(t_list **a, t_list **b)
{
	int		size;
	int		*numbers;
	int		max_index;
	int		max_bits;

	size = ft_lstsize(*a);
	if (size <= 5)
	{
		ft_tiny_sort(a, b, size);
		return (1);
	}
	numbers = gen_array_numbers(a, size);
	if (numbers == NULL)
		return (0);
	ft_quicksort(numbers, 0, size - 1);
	ft_index_numbers(a, numbers, size);
	free(numbers);
	max_index = ft_get_max_number(a);
	max_bits = ft_get_max_bits(max_index);
	ft_radix_sort(a, b, max_bits);
	return (1);
}
