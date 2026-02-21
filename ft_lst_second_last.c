/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_second_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:37:22 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/21 10:46:43 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_second_last(t_list *lst)
{
	t_list *second_last;
	
	if (!lst || !lst->next)
        return (NULL);
	while (lst->next)
	{
		second_last = lst;
		lst = lst->next;
	}
	return (second_last);
}