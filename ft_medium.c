/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:57:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/03 20:12:11 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_medium_sort(t_list **a, t_list **b, int size)
{
	int		rest;
	int		block_count;
	int		block_size;
	int		aux;

	block_count = ft_sqrt(size);
	block_size = size / block_count;
	rest = size - (block_count * block_size);
	aux = block_size;
	while(block_count != 0)
	{
		if(rest != 0 && block_count == 1)
			aux = aux + rest;
		ft_medium_sort_aux(a, b, aux, size);
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
	ft_medium_sort(a, b, size);
	return (numbers);
}
