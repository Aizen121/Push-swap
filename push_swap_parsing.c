/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaazouz <amaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:31:19 by amaazouz          #+#    #+#             */
/*   Updated: 2025/12/15 09:20:00 by amaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	valid_int(char *argv, t_list **stack)
{
	int	i;
	long int	nb;

	i = 0;
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	nb = ft_atol(argv);
	while (argv[i])
	{
		if (nb > 2147483647 || nb < -2147483648)
			handle_error();
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			handle_error();
		i++;
	}
	if (check_dup(*stack, (int)nb))
        handle_error();
	ft_lstadd_back(stack, ft_lstnew((int)nb));
}

int double_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
            return (1);
        i++;
    }
    return (0);
}

void	check_args(int argc, char **argv, t_list **stack)
{
	int i;
	char	**split_argv;

	i = 1;
	if (argc <= 2 && countword(argv[1], ' ') <= 1)
		exit(0);
	if (argc == 2 && countword(argv[1], ' ') > 1 && argv[1][0] != ' ' && argv[1][ft_strlen(argv[1]) - 1] != ' ')
	{
		i = 0;
		if (double_space(argv[1]) == 1)
			handle_error();
		split_argv = ft_split(argv[1], ' ');
		while (split_argv[i])
			valid_int(split_argv[i++], stack);
	}
	else
	{
		while (argv[i])
        	valid_int(argv[i++], stack);
	}	
}