/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:46:58 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/20 17:28:45 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nmemb * size > INT_MAX)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	while (((char *)result)[i] != '\0')
	{
		((char *)result)[i] = '\0';
		i++;
	}
	return (result);
}
