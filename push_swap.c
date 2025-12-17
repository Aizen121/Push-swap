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

void ft_index(t_list *stack)
{
    int count;
    t_list  *current;
    t_list  *other;

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

int index_max(t_list *stack)
{
    int max;

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

void    ft_radix_sort(t_list **stacka, t_list **stackb)
{
    int max;
    int i;
    int j;
    int size;
    t_list  *head;

    i = 0;
    max = index_max(*stacka);
    size = max + 1;
    while (max >> i != 0)
    {
        j = 0;
        while (j < size )
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv, &stack_a);
	ft_index(stack_a);
	ft_radix_sort(&stack_a, &stack_b);
	
	// --- DEBUT DE L'AFFICHAGE DU RESULTAT (A SUPPRIMER AVANT RENDU) ---
	printf("\n--- RESULTAT FINAL ---\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	// --- FIN DE L'AFFICHAGE ---

	// N'oublie pas de free ta stack ici idéalement
	return (0);
}