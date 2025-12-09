/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:12:29 by amaazouz          #+#    #+#             */
/*   Updated: 2025/12/09 16:25:26 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	**ft_split(char *s, char c);

typedef struct s_list
{
	int		value;
	int		index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);

#endif
