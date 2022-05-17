/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:00:08 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 13:50:12 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack *stack, t_node *new)
{
	if (!new)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new;
		stack->top->markup = 0;
	}
	else
	{
		new->prev = stack->top->prev;
		new->next = stack->top;
		stack->top->prev->next = new;
		stack->top->prev = new;
		stack->top = new;
	}
	stack->size++;
	stack->top->index = -1;
}
