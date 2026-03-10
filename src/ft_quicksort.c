/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:28:30 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/05 17:53:35 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *number, int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	pivot = number[last];
	i = first - 1;
	j = first;
	while (j < last)
	{
		if (number[j] < pivot)
		{
			i++;
			swap(&number[i], &number[j]);
		}
		j++;
	}
	swap(&number[i + 1], &number[last]);
	return (i + 1);
}

void	ft_quicksort(int *numbers, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = partition(numbers, first, last);
		ft_quicksort(numbers, first, pivot - 1);
		ft_quicksort(numbers, pivot + 1, last);
	}
}
