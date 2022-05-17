/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:01:50 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 17:02:05 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_markup_index(t_stack *stack)
{
	t_node	*temp;
	int		flag;

	temp = stack->top->prev;
	temp->markup = 0;
	flag = 0;
	while (!flag || temp->prev != stack->top->prev)
	{
		flag = 1;
		if (temp->prev->data < temp->data)
			temp->prev->markup = temp->markup;
		else
			temp->prev->markup = temp->markup + 1;
		temp = temp->prev;
	}
}
