/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:27:42 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/26 19:39:34 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (0);
	tmp = list[0]->next;
	list[0]->next = tmp->next;
	tmp->next = list[0];
	list[0] = tmp;
	return (1);
}

void	sa(t_list **a)
{
	if (ft_swap(a) != 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	if (ft_swap(b) != 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	if (a == NULL || *a == NULL || (*a)->next == NULL
		|| b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
