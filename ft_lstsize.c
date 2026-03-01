/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:13:17 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/01 15:13:38 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	nbrnodes;

	nbrnodes = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		nbrnodes++;
	}
	return (nbrnodes);
}
