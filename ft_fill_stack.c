/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:16:21 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 18:19:18 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack(t_stack *stack, char **numlist)
{
	int	i;

	i = 0;
	while (numlist[i])
		i++;
	i--;
	while (i >= 0)
	{
		ft_stack_push(stack, ft_new_node(ft_atoi(numlist[i])));
		i--;
	}
}
