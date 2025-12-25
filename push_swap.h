/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:12:29 by amaazouz          #+#    #+#             */
/*   Updated: 2025/12/15 09:17:18 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
}	t_list;

void	ft_free_tab(char **tab);
void    ft_free_stack(t_list **stack);
void	handle_error(void);
void	check_args(int argc, char **argv, t_list **stack);
int		double_space(char *str);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		check_dup(t_list *stack, int value);

char	**ft_split(char *s, char c);
long	ft_atol(char *str);
size_t	countword(char *s, char c);
size_t	ft_strlen(char *str);

void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse(t_list **stack);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);


void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	ft_index(t_list *stack);
void	ft_radix_sort(t_list **stacka, t_list **stackb);

int		get_min_index(t_list *stacka);
int		index_max(t_list *stack);
void	push_swap(t_list **stacka, t_list **stackb);
void	sort_three(t_list **stacka);
void	sort_five(t_list **stacka, t_list **stackb);
#endif
