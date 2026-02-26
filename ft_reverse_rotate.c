/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:54:48 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/26 18:48:04 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	last = ft_lstlast(list[0]);
	second_last = ft_lst_second_last(list[0]);
	second_last->next = NULL;
	ft_lstadd_front(list, last);
}

void	rra(t_list **a)
{
	ft_reverse_rotate(a);
		write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{	
	ft_reverse_rotate(b);
	write(1, "rra\n", 4);
}

void	rrr(t_list **a, t_list **b)
{	
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
