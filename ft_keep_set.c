/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:59:22 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/14 15:54:53 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_keep_set(t_stack *stack)
{
	t_node	*temp;
	int		i;
	int		flag;

	temp = stack->top;
	flag = 0;
	while (!flag || temp != stack->top)
	{
		flag = 1;
		temp->keep = 0;
		temp = temp->next;
	}
	i = 0;
	temp = stack->m_start;
	while (i < stack->m_length)
	{
		temp->keep = 1;
		temp = temp->next;
		i++;
	}
}
