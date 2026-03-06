/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:09:45 by ismonter          #+#    #+#             */
/*   Updated: 2026/03/06 19:26:11 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}	t_list;
/*
typedef struct s_matrix
{
	struct s_list 	*a;
	struct s_list 	*b;
	size_t			count_sa;
}
*/

int		*ft_parser(int argc, char **argv, int *numbers_size);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		count_total_numbers(int argc, char **argv);
char	**fill_matrix(int argc, char **argv, char **matrix, int i);
void	free_partial_matrix(char **matrix, int pos);
void	free_full_matrix(char **matrix);
int		free_error_matrix(char **matrix);
long	ft_atol(char *str);
int		matrix_len(char **matrix);
int		ft_check_int(long n);
int		ft_check_order(int *numbers, int numbers_size);
int		ft_isflag(char *s);
int		ft_flags(int argc, char **argv, int *numbers, int **flags);
t_list	*ft_lstnew(int number);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
int		ft_lstiter(t_list *a, int pos);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lst_second_last(t_list *lst);
t_list	*ft_fill_list(int *numbers, int numbers_size);
int		ft_swap(t_list **list);
int		ft_push(t_list **a, t_list **b);
int		ft_rotate(t_list **list);
int		ft_reverse_rotate(t_list **list);
void	ft_sort(t_list **a, t_list **b, int	**flags);
void	ft_simple(t_list **a, t_list **b);
void	*ft_medium(t_list **a, t_list **b);
void	ft_quicksort(int *numbers, int first, int last);
void	ft_tiny_sort(t_list **a,  t_list **b, int size);
int		ft_sqrt(int size);
void	ft_medium_sort_aux(t_list **a, t_list **b, int aux);
int		ft_lst_pos(t_list **b, int size, t_list *bigger);
int		*gen_array_numbers(t_list **a, int size);
void	ft_index_numbers(t_list **a, int *numbers, int size);
void	*ft_complex(t_list **a, t_list **b);
void	ft_adaptive(t_list **a, t_list **b);
float	ft_disorder_index(t_list **a);
void	ft_one_flag(t_list **a, t_list **b, int flags);
void	ft_two_flag(t_list **a, t_list **b, int **flags);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **b, t_list **a);
void	rrr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);

#endif