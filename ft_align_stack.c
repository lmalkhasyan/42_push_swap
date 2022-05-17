/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:10:42 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/14 18:57:34 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_align_stack(t_stack *a)
{
	t_node	*temp;
	int		flag;
	int		len;

	temp = a->top;
	flag = 0;
	len = 0;
	while (!flag || temp != a->top)
	{
		if (temp->index == 0)
			break ;
		flag = 1;
		temp = temp->next;
		len++;
	}
	if (a->size / 2 < len)
		while (a->top != temp)
			ft_stack_rrotate(a, "rra");
	else
		while (a->top != temp)
			ft_stack_rotate(a, "ra");
}
