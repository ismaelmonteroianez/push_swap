/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:09:45 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/20 19:25:28 by ismonter         ###   ########.fr       */
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
    int            number;
    struct s_list   *next;
}   t_list;


int     *ft_parser(int argc, char **argv, int *numbers_size);
char    **ft_split(char const *s, char c);
int     ft_isdigit(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	free_partial_matrix(char **matrix, int pos);
void    free_full_matrix(char **matrix);
int     free_error_matrix(char **matrix);
long	ft_atol(char *str);
int     matrix_len(char **matrix);
int	    ft_check_int(long n);
t_list	*ft_lstnew(int number);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_fill_list(int *numbers, int numbers_size);
void	ft_lstclear(t_list **lst);
int	    ft_check_order(int *numbers, int numbers_size);

#endif