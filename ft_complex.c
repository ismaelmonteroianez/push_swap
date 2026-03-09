/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:40:17 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/09 19:16:17 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_radix(t_list **a, t_list **b, int max_bits, t_bench *bench_result)
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
				pb(a, b, bench_result);
			else
				ra(a, bench_result);
			j++;
		}
		while ((*b) != NULL)
			pa(a, b, bench_result);
		i++;
	}
	return ;
}

int	ft_complex(t_list **a, t_list **b, t_bench *bench_result)
{
	int		size;
	int		*numbers;
	int		max_index;
	int		max_bits;

	bench_result->algorithm = 3;
	size = ft_lstsize(*a);
	if (size <= 5)
	{
		ft_tiny_sort(a, b, size, bench_result);
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
	ft_radix(a, b, max_bits, bench_result);
	return (1);
}
