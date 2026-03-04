/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:57:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/04 20:09:10 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_a(t_list **a, t_list **b, int size)
{
	t_list	*tmp;
	t_list	*bigger;
	
	while((*b)->next != NULL)
	{
		bigger = *b;
		tmp = (*b)->next;
		while(tmp != NULL)
		{
			if (bigger->number < tmp->number)
				bigger = tmp;
			tmp = tmp->next;
		}
		if (ft_lst_pos(b, size, bigger) < size / 2)
		{
			while(bigger != *b)
				rb(b);
			pa(a, b);
		}
		else
		{
			while(bigger != *b)
				rrb(b);
			pa(a, b);
		}
		size--;
	}
	pa(a, b);
	return ;
}

void	ft_move_to_b(t_list **a, t_list **b, int size)
{
	int		rest;
	int		block_count;
	int		block_size;
	int		aux;
	int		size_aux;

	size_aux = size;
	block_count = ft_sqrt(size_aux);
	block_size = size_aux / block_count;
	rest = size_aux - (block_count * block_size);
	aux = block_size;
	while(block_count != 0)
	{
		if(rest != 0 && block_count == 1)
			aux = aux + rest;
		ft_medium_sort_aux(a, b, aux, size_aux);
		block_count--;
		aux = aux + block_size;
		size_aux = size_aux - block_size;
	}
	ft_move_to_a(a, b, size);
	return ;
}

void	ft_index_numbers(t_list **a, int *numbers, int size)
{
	t_list	*tmp;
	int		i;
	
	tmp = *a;
	while(tmp != NULL)
	{
		i = 0;
		while(i < size)
		{
			if(numbers[i] == tmp->number)
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

int		*gen_array_numbers(t_list **a, int size)
{
	int		*numbers;
	int		i;
	t_list	*tmp;

	numbers = ft_calloc(sizeof(int), size);
	if (numbers == NULL)
		return (NULL);
	tmp = *a;
	i = 0;
	while(tmp != NULL)
	{
		numbers[i] = tmp->number;
		i++;
		tmp = tmp->next;
	}
	return (numbers);
}

void	*ft_medium(t_list **a, t_list **b)
{
    int		size;
	int		*numbers;
	int		block_count;
	int		block_size;

	size = ft_lstsize(*a);
	numbers = gen_array_numbers(a, size);
	if (numbers == NULL)
		return (NULL);
	ft_quicksort(numbers, 0, size - 1);
	ft_index_numbers(a, numbers, size);
	free(numbers);
	ft_move_to_b(a, b, size);
	return (numbers);
}
