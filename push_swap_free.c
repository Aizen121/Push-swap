/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:50:00 by amaazouz          #+#    #+#             */
/*   Updated: 2025/12/11 14:50:13 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_tab(char **tab)
{
    int i;

    i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void    ft_free_stack(t_list **stack)
{
    t_list	*tmp;
	
    if (!*stack || !stack)
		return ;
	while(*stack)
    {
    	tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
    }
    *stack = NULL;
}