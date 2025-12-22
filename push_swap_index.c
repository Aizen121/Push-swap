/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:13:42 by amaazouz          #+#    #+#             */
/*   Updated: 2025/12/08 20:09:18 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list *stack)
{
	int		count;
	t_list	*current;
	t_list	*other;

	current = stack;
	while (current)
	{
		count = 0;
		other = stack;
		while (other)
		{
			if (other->value < current->value)
				count++;
			other = other->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	index_max(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_min_index(t_list *stacka)
{
	int		min;
	t_list	*tmp;
	int		min_pos;
	int		current_pos;

	if (!stacka)
		return (-1);
	tmp = stacka;
	min_pos = 0;
	current_pos = 0;
	min = stacka->value;
	while (tmp)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			min_pos = current_pos;
		}
		current_pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	push_swap(t_list **stacka, t_list **stackb)
{
	int	size;

	size = index_max(*stacka) + 1;
	if (!*stacka)
		return ;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stacka)->value > (*stacka)->next->value)
			sa(stacka);
	}
	else if (size == 3)
		sort_three(stacka);
	else if (size == 4 || size == 5)
		sort_five(stacka, stackb);
	else
		ft_radix_sort(stacka, stackb);
}
