/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:28:42 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/16 16:07:18 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nextfirst(t_node *first, t_node **second)
{
	int	secondlen;
	int	flag;

	flag = 0;
	secondlen = 0;
	while (first->markup == (*second)->markup
		&& (!flag || first->next == *second))
	{
		flag = 1;
		*second = (*second)->next;
		secondlen++;
	}
	return (secondlen);
}

static t_node	*ft_startmarkup(t_node *first, t_node *second, int *firstlen)
{
	*firstlen = 0;
	while (first->markup != second->markup)
	{
		if (first->data > second->data)
			break ;
		first = first->next;
		(*firstlen)++;
	}
	return (first);
}

static void	ft_set_markup(int length, t_node *m_start, t_stack *stack)
{
	stack->m_length = length;
	stack->m_start = m_start;
}

static void	ft_next_start(t_node **first, int *secondlen)
{
	while ((*first)->markup == (*first)->next->markup)
	{
		(*secondlen)--;
		*first = (*first)->next;
	}
	(*secondlen)--;
	*first = (*first)->next;
}

void	ft_markup(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp_markup;
	int		firstlen;
	int		secondlen;

	first = stack->top;
	second = first;
	secondlen = ft_nextfirst(first, &second);
	while (1)
	{
		temp_markup = ft_startmarkup(first, second, &firstlen);
		if (ft_markuplength(first) > stack->m_length)
			ft_set_markup(ft_markuplength(first), first, stack);
		if (secondlen - firstlen + 1 >= stack->m_length)
			ft_set_markup(secondlen - firstlen + 1, temp_markup, stack);
		if (second->markup != second->next->markup)
			ft_next_start(&first, &secondlen);
		if (first->markup == 0)
			break ;
		second = second->next;
		secondlen++;
	}
}
