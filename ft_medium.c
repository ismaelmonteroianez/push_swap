/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:57:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/02 19:11:11 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

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

void    ft_medium(t_list **a, t_list **b)
{
    int		size;

	size = ft_lstsize(*a);
	gen_array_numbers(*a, size);
	if (gen_array_numbers == NULL)
		return (NULL);
	
    
}
