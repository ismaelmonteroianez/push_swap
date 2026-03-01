/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:58:27 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/01 18:44:22 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*smaller;
	
	while(a[0]->next != NULL)
	{	
		smaller = *a;
		tmp = a[0]->next;
		while(tmp != NULL)
		{
			if (smaller->number > tmp->number)
				smaller = tmp;
			tmp = tmp->next;
		}
		while(smaller != *a)
			ra(a);
		pb(a, b);
	}
	pb(a, b);
	while(b[0]->next != NULL)
		pa(a, b);
	pa(a, b);
	return ;
}
