/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:27:23 by amaazouz          #+#    #+#             */
/*   Updated: 2025/11/08 22:11:28 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	char	*d = " world";
// 	t_list	*lst = NULL;
// 	t_list	*elem;

// 	elem = ft_lstnew((char *)d);
// 	ft_lstadd_front(&lst, elem);
// 	ft_lstadd_front(&lst, ft_lstnew("hello"));

// 	t_list *current_node = lst;	
// 	while (current_node)
// 	{
// 		printf("%s", (char *)current_node->content);
// 		current_node = current_node->next;
// 	}
	//printf("%s", (char *)lst->content);
	//return (0);
//}	
