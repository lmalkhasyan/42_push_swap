/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markuplength.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:05:42 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/16 16:06:03 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_markuplength(t_node *first)
{
	int		len;
	int		flag;
	t_node	*temp;

	temp = first;
	flag = 0;
	len = 1;
	while (first->markup == first->next->markup && (!flag || temp != first))
	{
		flag = 1;
		first = first->next;
		len++;
	}
	if (first->markup == 0 && first->next->markup != 0
		&& first->data < first->next->data)
	{
		first = first->next;
		len++;
		while (first->markup == first->next->markup)
		{
			first = first->next;
			len++;
		}
	}
	return (len);
}
