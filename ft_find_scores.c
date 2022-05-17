/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_scores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:08:38 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 19:23:41 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_down(int a_bot, int b_bot, t_stack *b)
{
	b->a_updown = (-1 * a_bot);
	b->b_updown = (-1 * b_bot);
}

static void	ft_set_up(int a_top, int b_top, t_stack *b)
{
	b->a_updown = (1 * a_top);
	b->b_updown = (1 * b_top);
}

int	ft_element_score(int b_top, t_stack *b, int a_top, int a_bot)
{
	int	b_bot;
	int	score;

	b_bot = b->size - b_top;
	if (b->size == 1)
		b_bot = 0;
	score = ft_min4(a_top + b_bot, b_top + a_bot, ft_abs(a_top - b_top)
			+ ft_min(a_top, b_top), ft_abs(a_bot - b_bot)
			+ ft_min(a_bot, b_bot));
	if (score == ft_abs(a_top - b_top) + ft_min(a_top, b_top))
		ft_set_up(a_top, b_top, b);
	else if (score == ft_abs(a_bot - b_bot) + ft_min(a_bot, b_bot))
		ft_set_down(a_bot, b_bot, b);
	else if (score == a_top + b_bot)
	{
		b->a_updown = (1 * a_top);
		b->b_updown = (-1 * b_bot);
	}
	else if (score == b_top + a_bot)
	{
		b->a_updown = (-1 * a_bot);
		b->b_updown = (1 * b_top);
	}
	return (score);
}

static int	ft_num_top(t_stack *a, int index)
{
	t_node	*temp;
	int		flag;
	int		a_toplen;
	int		templength;

	temp = a->top;
	a_toplen = 0;
	flag = 0;
	while (!flag || temp != a->top)
	{
		flag = 1;
		if (temp->prev->index > temp->index)
			templength = a_toplen;
		else if (index > temp->prev->index && index < temp->index)
			break ;
		temp = temp->next;
		a_toplen++;
	}
	if (a_toplen == a->size || index == 0)
		return (templength);
	return (a_toplen);
}

void	ft_find_scores(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		flag;
	int		b_toplen;
	int		a_bot;
	int		a_top;

	temp = b->top;
	flag = 0;
	b_toplen = 0;
	while (!flag || temp != b->top)
	{
		flag = 1;
		a_top = ft_num_top(a, temp->index);
		a_bot = a->size - a_top;
		if (a->size == 1)
			a_bot = 0;
		temp->keep = ft_element_score(b_toplen, b,
				a_top, a_bot);
		temp->a_updown = b->a_updown;
		temp->b_updown = b->b_updown;
		temp = temp->next;
		b_toplen++;
	}
}
