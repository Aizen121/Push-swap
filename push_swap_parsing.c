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

void ft_exit_error(t_list **stack)
{
    ft_free_stack(stack);
    write(2, "Error\n", 6);
    exit(1);
}

int	valid_int(char *argv, t_list **stack)
{
	int			i;
	long int	nb;

	i = 0;
	if (!argv[i])
		exit (0);
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	nb = ft_atol(argv);
	while (argv[i])
	{
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	if (check_dup(*stack, (int)nb))
		return (0);
	ft_lstadd_back(stack, ft_lstnew((int)nb));
	return (1);
}

int	double_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static void process_string(char *str, t_list **stack)
{
	char	**tab;
	int		i;

	if (double_space(str))
		ft_exit_error(stack);
	tab = ft_split(str, ' ');
	if (!tab)
		ft_exit_error(stack);
	i = 0;
	while (tab[i])
	{
		if (!valid_int(tab[i], stack))
		{
			ft_free_tab(tab);
			ft_exit_error(stack);
		}
		i++;
	}
	ft_free_tab(tab);
}

void	check_args(int argc, char **argv, t_list **stack)
{
	int		i;
	char	**split_argv;

	i = 1;
	if (argc <= 2 && countword(argv[1], ' ') <= 1)
		exit(0);
	if (argc == 2 && countword(argv[1], ' ') > 1
		&& argv[1][0] != ' ' && argv[1][ft_strlen(argv[1]) - 1] != ' ')
	{
		process_string(argv[1], stack);
	}
	else
	{
		while (i < argc)
		{
			if (!valid_int(argv[i], stack))
				ft_exit_error(stack);
			i++;
		}
	}
}
