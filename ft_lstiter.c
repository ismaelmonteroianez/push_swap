/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:27:19 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/01 15:45:47 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstiter(t_list *a, int pos)
{
	t_list *tmp;
	int 	i;

	tmp = a;
	i = 0;
	while(i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->number);
}
