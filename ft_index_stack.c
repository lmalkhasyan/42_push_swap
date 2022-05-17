/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:26:38 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/07 18:31:23 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_get_next_min(t_node *stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = stack;
	if (head)
	{
		while (head->next != stack)
		{
			if ((head->index == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
		if ((head->index == -1) && (!has_min || head->data < min->data))
		{
			min = head;
			has_min = 1;
		}
	}
	return (min);
}

void	ft_index_stack(t_stack *stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = ft_get_next_min(stack->top);
	while (head)
	{
		head->index = index++;
		head = ft_get_next_min(stack->top);
	}
}
