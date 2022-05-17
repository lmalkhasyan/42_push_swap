/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:36:38 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 17:21:02 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a, NULL);
	ft_stack_rotate(b, "rr");
}

static void	ft_stack_rrr(t_stack *a, t_stack *b)
{
	ft_stack_rrotate(a, NULL);
	ft_stack_rrotate(b, "rrr");
}

static t_node	*ft_min_score(t_stack *stack)
{
	t_node	*temp;
	int		flag;
	t_node	*min;

	min = stack->top;
	temp = stack->top;
	flag = 0;
	while (!flag || temp != stack->top)
	{
		if (temp->keep < min->keep)
			min = temp;
		flag = 1;
		temp = temp->next;
	}
	return (min);
}

void	ft_tostack_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	while (b->top != NULL)
	{
		ft_find_scores(a, b);
		node = ft_min_score(b);
		while (node->a_updown > 0 && node->b_updown > 0
			&& node->a_updown-- && node->b_updown--)
			ft_stack_rr(a, b);
		while (node->a_updown < 0 && node->b_updown < 0
			&& node->a_updown++ && node->b_updown++)
			ft_stack_rrr(a, b);
		while (node->a_updown > 0 && node->a_updown--)
			ft_stack_rotate(a, "ra");
		while (node->a_updown < 0 && node->a_updown++)
			ft_stack_rrotate(a, "rra");
		while (node->b_updown > 0 && node->b_updown--)
			ft_stack_rotate(b, "rb");
		while (node->b_updown < 0 && node->b_updown++)
			ft_stack_rrotate(b, "rrb");
		ft_stack_papb(a, b, "pa");
	}
}
