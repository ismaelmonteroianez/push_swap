/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:38:58 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/26 18:47:30 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (0);
	tmp = list[0]->next;
	ft_lstadd_back(list, list[0]);
	list[0]->next = NULL;
	list[0] = tmp;
	return (1);
}

void	ra(t_list **a)
{
	if (ft_rotate(a) != 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	if (ft_rotate(b) != 0)
		write(1, "rb\n", 3);
}

void	rr(t_list **b, t_list **a)
{
	if (ft_rotate(a) != 0 && ft_rotate(b) != 0) // si a rota pero b no puede no debe hacer ninguna, error
		write(1, "rr\n", 3);
}
