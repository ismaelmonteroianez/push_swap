/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:57:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/10 19:11:27 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_move_to_a(t_list **a, t_list **b, int size, t_bench *bench_result)
{
	t_list	*tmp;
	t_list	*bigger;

	while ((*b)->next != NULL)
	{
		bigger = *b;
		tmp = (*b)->next;
		while (tmp != NULL)
		{
			if (bigger->number < tmp->number)
				bigger = tmp;
			tmp = tmp->next;
		}
		while (bigger != *b)
		{
			if (ft_lst_pos(b, bigger) < size / 2)
				rb(b, bench_result);
			else
				rrb(b, bench_result);
		}
		pa(a, b, bench_result);
		size--;
	}
	pa(a, b, bench_result);
}

void	ft_move_to_b(t_list **a, t_list **b, int size, t_bench *bench_result)
{
	int		rest;
	int		block_count;
	int		block_size;
	int		aux;
	int		i;

	block_count = ft_sqrt(size);
	block_size = size / block_count;
	rest = size - (block_count * block_size);
	aux = block_size;
	while (block_count != 0)
	{
		i = 0;
		if (rest != 0 && block_count == 1)
			aux = aux + rest;
		while (i < size)
		{
			ft_medium_aux(a, b, aux, bench_result);
			i++;
		}
		block_count--;
		aux = aux + block_size;
		size = size - block_size;
	}
	return ;
}

void	ft_index_numbers(t_list **a, int *numbers, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (numbers[i] == tmp->number)
			{
				tmp->index = i;
				i = size;
			}
			i++;
		}
		tmp = tmp->next;
	}
	return ;
}

int	*gen_array_numbers(t_list **a, int size)
{
	int		*numbers;
	int		i;
	t_list	*tmp;

	numbers = ft_calloc(sizeof(int), size);
	if (numbers == NULL)
		return (NULL);
	tmp = *a;
	i = 0;
	while (tmp != NULL)
	{
		numbers[i] = tmp->number;
		i++;
		tmp = tmp->next;
	}
	return (numbers);
}

int	ft_medium(t_list **a, t_list **b, t_bench *bench_result)
{
	int		size;
	int		*numbers;

	bench_result->algorithm = 2;
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
	ft_move_to_b(a, b, size, bench_result);
	ft_move_to_a(a, b, size, bench_result);
	return (1);
}
