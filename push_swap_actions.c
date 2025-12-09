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

void	ft_sa(t_list **stacka)
{
	t_list	*first;
	t_list	*second;

	if (!stacka)
		return ;
	first = *stacka;
	second = first->next;
	first->next= second->next;
	second->next = first;
	*stacka = second;
}

void	ft_sb(t_list **stackb)
{
	t_list	*first;
	t_list	*second;

	if (!stackb)
		return ;
	first = *stackb;
	second = first->next;
	first->next= second->next;
	second->next = first;
	*stackb = second;
}

void	ft_ss(t_list **stacka, t_list **stackb)
{
		ft_sa(stacka);
		ft_sb(stackb);
}

int	main(void)
{
	
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew(42));
	ft_lstadd_front(&lst, ft_lstnew(12));

	t_list *temp = lst;
	while (temp)
	{
		printf("%d\n",temp->content);
		temp = temp->next;
	}
	ft_sa(&lst);
	temp = lst;
	while (temp)
	{
		printf("%d\n",temp->content);
		temp = temp->next;
	}
	return (0);
}	
