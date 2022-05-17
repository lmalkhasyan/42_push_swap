/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:15:16 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 18:04:14 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_node	*temp_top;
	t_node	*next;

	if (stack == NULL)
		return (1);
	temp_top = stack->top;
	next = stack->top->next;
	while (stack->top != next)
	{
		if (temp_top->data > next->data)
			return (0);
		temp_top = next;
		next = next->next;
	}
	ft_stack_clear(stack);
	return (1);
}
