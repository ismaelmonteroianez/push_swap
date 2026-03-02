/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:57:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/02 20:11:29 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	size = ft_lstsize(*a);
	numbers = gen_array_numbers(a, size);
	if (numbers == NULL)
		return (NULL);
	ft_quicksort(numbers, 0, size - 1);
	int i = 0;
	while(i < size)
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	return (numbers);
}
