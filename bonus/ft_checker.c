/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:12:52 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 18:14:11 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a, NULL);
	ft_stack_rotate(b, NULL);
}

static void	ft_stack_rrr(t_stack *a, t_stack *b)
{
	ft_stack_rrotate(a, NULL);
	ft_stack_rrotate(b, NULL);
}

static void	ft_stack_ss(t_stack *a, t_stack *b)
{
	ft_stack_swap(a, NULL);
	ft_stack_swap(b, NULL);
}

static int	ft_do_cmd(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "rr\n"))
		ft_stack_rr(a, b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_stack_rrr(a, b);
	else if (!ft_strcmp(line, "sa\n"))
		ft_stack_swap(a, NULL);
	else if (!ft_strcmp(line, "sb\n"))
		ft_stack_swap(b, NULL);
	else if (!ft_strcmp(line, "ss\n"))
		ft_stack_ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		ft_stack_papb(a, b, NULL);
	else if (!ft_strcmp(line, "pb\n"))
		ft_stack_papb(b, a, NULL);
	else if (!ft_strcmp(line, "ra\n"))
		ft_stack_rotate(a, NULL);
	else if (!ft_strcmp(line, "rb\n"))
		ft_stack_rotate(b, NULL);
	else if (!ft_strcmp(line, "rra\n"))
		ft_stack_rrotate(a, NULL);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_stack_rrotate(b, NULL);
	else
		return (1);
	return (0);
}

void	ft_checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = "1";
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line)
		{
			if (ft_do_cmd(a, b, line))
			{
				write(2, "Wrong Instruction\n", 18);
				exit(1);
			}
		}
		if (line)
			free(line);
	}
	if (b->top == NULL && ft_is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
