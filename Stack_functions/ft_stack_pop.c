/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:42:29 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/06 21:35:04 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_pop(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	if (!stack->top)
		return ;
	else if (stack->top == stack->top->next)
	{
		free(stack->top);
		stack->top = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		temp->prev->next = stack->top;
		stack->top->prev = temp->prev;
		if (temp)
			free(temp);
	}
	stack->size--;
}
