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

void	sort_three(t_list **stacka)
{
	int	max;

	max = index_max(*stacka);
	if ((*stacka)->index == max)
		ra(stacka);
	else if ((*stacka)->next->index == max)
		rra(stacka);
	if ((*stacka)->index > (*stacka)->next->index)
		sa(stacka);
}

void	ft_radix_sort(t_list **stacka, t_list **stackb)
{
	int		max;
	int		i;
	int		j;
	int		size;
	t_list	*head;

	i = 0;
	max = index_max(*stacka);
	size = max + 1;
	while (max >> i != 0)
	{
		j = 0;
		while (j < size)
		{
			head = *stacka;
			if (((head->index >> i) & 1) == 1)
				ra(stacka);
			else
				pb(stacka, stackb);
			j++;
		}
		while (*stackb)
			pa(stacka, stackb);
		i++;
	}
}

void	sort_five(t_list **stacka, t_list **stackb)
{
	int	min;
	int	size;

	size = index_max(*stacka) + 1;
	while (size > 3)
	{
		min = get_min_index(*stacka);
		if (min <= size / 2)
		{
			while (min-- > 0)
				ra(stacka);
		}
		else
		{
			while (min++ < size)
				rra(stacka);
		}
		pb(stacka, stackb);
		size--;
	}
	sort_three(stacka);
	while (*stackb)
		pa(stacka, stackb);
}


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv, &stack_a);
	ft_index(stack_a);
	push_swap(&stack_a, &stack_b);
	tmp = stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
