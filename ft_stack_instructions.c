/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:44:38 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/11 18:23:04 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack *stack, char *text)
{
	if (stack->size < 2 || !stack->top)
		return ;
	ft_swapint(&(stack->top->data), &(stack->top->next->data));
	ft_swapint(&(stack->top->index), &(stack->top->next->index));
	if (text)
	{
		write(1, text, ft_strlen(text));
		write(1, "\n", 1);
	}
}

void	ft_stack_papb(t_stack *dest, t_stack *src, char *text)
{
	if (src->size == 0 || src->top == NULL)
		return ;
	ft_stack_push(dest, ft_new_node(src->top->data));
	dest->top->index = src->top->index;
	ft_stack_pop(src);
	if (text)
	{
		write(1, text, ft_strlen(text));
		write(1, "\n", 1);
	}
}

void	ft_stack_rotate(t_stack *stack, char *text)
{
	if (!stack->top || stack->size < 2)
		return ;
	stack->top = stack->top->next;
	if (text)
	{
		write(1, text, ft_strlen(text));
		write(1, "\n", 1);
	}
}

void	ft_stack_rrotate(t_stack *stack, char *text)
{
	if (!stack->top || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
	if (text)
	{
		write(1, text, ft_strlen(text));
		write(1, "\n", 1);
	}
}
