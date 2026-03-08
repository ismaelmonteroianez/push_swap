/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:11:31 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:34 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strategy_used(t_bench *bench_result)
{
	write(2, "[bench] strategy: ", 18);
	if(bench_result->strategy == 1)
		write(2, "Simple / O(n^2)", 15);
	else if(bench_result->strategy == 2)
		write(2, "Medium / O(n√n)", 17);
	else if(bench_result->strategy == 3)
		write(2, "Complex / O(n log n)", 20);
	else if(bench_result->strategy == 4)
	{
		write(2, "Adaptive / ", 11);
		if (bench_result->algorithm == 1)
			write(2, "O(n^2)", 6);
		else if (bench_result->algorithm == 2)
			write(2, "O(n√n)", 8);
		else if (bench_result->algorithm == 3)
			write(2, "O(n log n)", 10);
	}
	write(2, "\n", 1);
}	

void	ft_print_rotate_reverse(t_bench *bench_result)
{
	write(2, "[bench] ra: ", 12);
	ft_printnbr(bench_result->ra);
	write(2, " ", 1);
	write(2, "rb: ", 4);
	ft_printnbr(bench_result->rb);
	write(2, " ", 1);
	write(2, "rr: ", 4);
	ft_printnbr(bench_result->rr);
	write(2, " ", 1);
	write(2, "rra: ", 5);
	ft_printnbr(bench_result->rra);
	write(2, " ", 1);
	write(2, "rrb: ", 5);
	ft_printnbr(bench_result->rrb);
	write(2, " ", 1);
	write(2, "rrr: ", 5);
	ft_printnbr(bench_result->rrr);
	write(2, "\n", 1);
}

void	ft_print_swap_push(t_bench *bench_result)
{
	write(2, "[bench] sa: ", 12);
	ft_printnbr(bench_result->sa);
	write(2, " ", 1);
	write(2, "sb: ", 4);
	ft_printnbr(bench_result->sb);
	write(2, " ", 1);
	write(2, "ss: ", 4);
	ft_printnbr(bench_result->ss);
	write(2, " ", 1);
	write(2, "pa: ", 4);
	ft_printnbr(bench_result->pa);
	write(2, " ", 1);
	write(2, "pb: ", 4);
	ft_printnbr(bench_result->pa);
	write(2, "\n", 1);
}

void	ft_print_total_ops(t_bench *bench_result)
{
	int	total_ops;
	
	write(2, "[bench] total_ops: ", 19);
	total_ops = bench_result->pa + bench_result->pb +
	bench_result->sa + bench_result->sb + bench_result->ss +
	bench_result->ra + bench_result->rb + bench_result->rr +
	bench_result->rra + bench_result->rrb + bench_result->rrr;
	ft_printnbr(total_ops);
	write(2, "\n", 1);
}

void	ft_print_disorder(t_bench *bench_result)
{
	int	disorder;
	
	write(2, "[bench] disorder: ", 18);
	disorder = bench_result->disorder * 10000;
	if (disorder == 10000)
	{
		ft_printnbr(100);
		write(2, ".", 1);
		ft_printnbr(0);
		ft_printnbr(0);
	}
	else
	{
	ft_printnbr(disorder/1000);
	if (disorder/1000 != 0)
		disorder = disorder / 10;
	ft_printnbr(disorder/100);
	write(2, ".", 1);
	disorder = disorder % 100;
	ft_printnbr(disorder/10);
	ft_printnbr(disorder%10);
	}
	write(2, "%\n", 2);
	
}

void	ft_bench(t_bench *bench_result)
{
	ft_print_disorder(bench_result);	
	ft_strategy_used(bench_result);
	ft_print_total_ops(bench_result);
	ft_print_swap_push(bench_result);
	ft_print_rotate_reverse(bench_result);
}
