/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:09:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/27 19:56:50 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_imprimir(t_list	*a, t_list	*b)
{
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
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*numbers;
	int		numbers_size;
	int		*flags;

	b = NULL;
	numbers_size = 0;
	numbers = ft_parser(argc, argv, &numbers_size);
	if (numbers == NULL)
		return (0);
	if (ft_flags(argc, argv, numbers, &flags) == 0)
		return (0);
	a = ft_fill_list(numbers, numbers_size);
	if (a == NULL)
		return (0);
	ft_imprimir(a, b);
	return (0);
}
