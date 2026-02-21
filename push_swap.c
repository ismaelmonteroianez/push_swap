/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:09:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/21 11:23:19 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*numbers;
	int		numbers_size;

	b = NULL;
	numbers_size = 0;
	numbers = ft_parser(argc, argv, &numbers_size);
	if (numbers == NULL)
		return(0);
	a = ft_fill_list(numbers, numbers_size);
	if (a == NULL)
		return (0);

	//Funcion para imprimir, solo descomentar para probar
	/*
	ft_rotate(&a);
	
	printf("Lista a:\n");
	while(a)
	{
		printf("%d\n", a->number);
		a = a->next;
	}
	printf("Lista b:\n");
	while(b)
	{
		printf("%d\n", b->number);
		b = b->next;
	}
	return (0);
	*/
}
