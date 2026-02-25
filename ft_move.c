/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 09:40:26 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/25 20:54:40 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*tmp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
    	return;
	
	tmp = list[0]->next; 
	list[0]->next = tmp->next;
	tmp->next = list[0];
	list[0] = tmp; 
}

void	ft_rotate(t_list **list)
{
	t_list *tmp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
    	return;
	tmp = list[0]->next;
	ft_lstadd_back(list, list[0]);
	list[0]->next = NULL;
	list[0] = tmp;
}
void	ft_reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
    	return;
	last = ft_lstlast(list[0]);
	second_last = ft_lst_second_last(list[0]);
	second_last->next = NULL;
	ft_lstadd_front(list, last);
}
