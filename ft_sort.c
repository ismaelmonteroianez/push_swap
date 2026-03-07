/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:51:03 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/07 18:31:43 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialize(t_list **a, t_bench *bench_result)
{
	bench_result->disorder = ft_disorder_index(a);
	bench_result->pa = 0;
	bench_result->pb = 0;
	bench_result->ra = 0;
	bench_result->rb = 0;
	bench_result->rr = 0;
	bench_result->rra = 0;
	bench_result->rrb = 0;
	bench_result->rrr = 0;
	bench_result->sa = 0;
	bench_result->sb = 0;
	bench_result->ss = 0;
	bench_result->strategy = 0;
	bench_result->algorithm = 0;
}

int	ft_one_flag(t_list **a, t_list **b, int flags, t_bench *bench_result)
{
	if (flags == 1)
	{
		bench_result->strategy = 1;
		ft_simple(a, b, bench_result);
	}
	else if (flags == 2)
	{
		bench_result->strategy = 2;
		return (ft_medium(a, b, bench_result));
	}
	else if (flags == 3)
	{
		bench_result->strategy = 3;
		return (ft_complex(a, b, bench_result));
	}
	else if (flags == 4)
		return (ft_adaptive(a, b, bench_result));
	else if (flags == 5)
	{
		if (ft_adaptive(a, b, bench_result) == 0)
			return (0);
		ft_bench(bench_result);
	}
	return (1);
}

void	ft_two_flag(t_list **a, t_list **b, int **flags, t_bench *bench_result)
{
	if ((*flags)[0] == 5)
	{
		if (ft_one_flag(a, b, (*flags)[1], bench_result) == 0)
			return ;
		ft_bench(bench_result);
	}
	else
	{
		if (ft_one_flag(a, b, (*flags)[0], bench_result) == 0)
			return ;
		ft_bench(bench_result);
	}
}

void	ft_sort(t_list **a, t_list **b, int	**flags)
{
	int		num_flags;
	t_bench	*bench_result;

	bench_result = ft_calloc(1 , sizeof(t_bench));
	if (bench_result == NULL)
		{
			ft_lstclear(a);
			free(*flags);
			return ;
		}
	ft_initialize(a, bench_result);
	num_flags = 0;
	while ((*flags)[num_flags] != 0)
		num_flags++;
	if (num_flags == 0)
		ft_adaptive(a, b, bench_result);
	else if (num_flags == 1)
		ft_one_flag(a, b, (*flags)[0], bench_result);
	else if (num_flags == 2)
		ft_two_flag(a, b, flags, bench_result);
	free(bench_result);
	ft_lstclear(a);
	free(*flags);
	return ;
}
