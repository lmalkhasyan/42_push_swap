/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:58:23 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 15:07:44 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_false(t_stack *stack)
{
	t_node	*temp;
	int		flag;

	temp = stack->top;
	flag = 0;
	while (!flag || temp != stack->top)
	{
		flag = 1;
		if (temp->keep == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	ft_test_swap(t_stack *a, t_node *mark, int *tsize)
{
	mark = a->m_start;
	*tsize = a->m_length;
	ft_stack_swap(a, NULL);
	ft_markup_index(a);
	ft_markup(a);
}

static void	ft_back_swap(t_stack *a, t_node *mark, int tsize)
{
	a->m_start = mark;
	a->m_length = tsize;
	ft_stack_swap(a, NULL);
}

void	ft_tostack_b(t_stack *a, t_stack *b)
{
	t_node	*mark;
	int		tsize;

	mark = NULL;
	while (ft_check_false(a))
	{
		ft_test_swap(a, mark, &tsize);
		if (a->m_length <= tsize)
			ft_back_swap(a, mark, tsize);
		else
		{
			ft_keep_set(a);
			write(1, "sa\n", 3);
			if (!ft_check_false(a))
				break ;
		}
		if (a->top->keep == 0)
			ft_stack_papb(b, a, "pb");
		else if (a->size > 5)
			ft_stack_rotate(a, "ra");
		else
			ft_stack_rrotate(a, "rra");
	}
}
