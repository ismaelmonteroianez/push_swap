/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:50:07 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/20 19:09:42 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*lst_aux;

	while (lst[0] != NULL)
	{
		lst_aux = lst[0]->next;
		free(lst[0]);
		lst[0] = lst_aux;
	}
}
