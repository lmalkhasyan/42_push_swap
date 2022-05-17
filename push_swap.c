/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:18:42 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/17 16:38:23 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**numlist;
	t_stack	a;
	t_stack	b;

	a = (t_stack){.top = NULL, .size = 0, .m_length = 0, .m_start = NULL};
	b = (t_stack){.top = NULL, .size = 0};
	if (argc < 2)
		ft_exit_error("Push_swap: few arguments", NULL);
	numlist = ft_checkargvs(argc, argv);
	ft_fill_stack(&a, numlist);
	ft_free_matrix(&numlist);
	if (ft_is_sorted(&a))
		return (0);
	ft_index_stack(&a);
	ft_markup_index(&a);
	ft_markup(&a);
	ft_keep_set(&a);
	ft_tostack_b(&a, &b);
	ft_tostack_a(&a, &b);
	ft_align_stack(&a);
	ft_stack_clear(&a);
	while (1);

	return (0);
}
