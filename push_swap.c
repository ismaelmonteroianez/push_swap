/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:09:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/20 19:14:28 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*numbers;
	int		numbers_size;

	numbers_size = 0;
	numbers = ft_parser(argc, argv, &numbers_size);
	if (numbers == NULL)
		return(0);
	a = ft_fill_list(numbers, numbers_size);
	if (a == NULL)
		return (0);
}
