/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:00:12 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/26 18:08:22 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_fill_list(int *numbers, int numbers_size)
{
	t_list	*a;
	t_list	*tmp;
	int		i;

	i = 0;
	a = NULL;
	while (i < numbers_size)
	{
		tmp = ft_lstnew(numbers[i]);
		if (tmp == NULL)
		{
			ft_lstclear(&a);
			free(numbers);
			return (NULL);
		}
		ft_lstadd_back(&a, tmp);
		i++;
	}
	free(numbers);
	return (a);
}
