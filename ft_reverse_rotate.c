/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:54:48 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/26 19:56:39 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (0);
	last = ft_lstlast(list[0]);
	second_last = ft_lst_second_last(list[0]);
	second_last->next = NULL;
	ft_lstadd_front(list, last);
	return (1);
}

void	rra(t_list **a)
{
	if (ft_reverse_rotate(a) != 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{	
	if (ft_reverse_rotate(b) != 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{	
	if (a == NULL || *a == NULL || (*a)->next == NULL
		|| b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
