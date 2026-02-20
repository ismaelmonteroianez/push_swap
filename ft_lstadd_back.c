/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:35:15 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/20 18:50:31 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_aux;

	if (lst == NULL || new == NULL)
		return ;
	lst_aux = lst[0];
	if (lst_aux != NULL)
	{
		while (lst_aux->next != NULL)
		{
			lst_aux = lst_aux->next;
		}
		lst_aux->next = new;
	}
	else
		lst[0] = new;
}
