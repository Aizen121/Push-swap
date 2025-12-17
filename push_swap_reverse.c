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

void	rra(t_list **stack_a)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
    reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
}