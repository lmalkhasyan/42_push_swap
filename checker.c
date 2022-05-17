/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:56:57 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 18:15:11 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**numlist;

	a = (t_stack){.top = NULL, .size = 0, .m_length = 0, .m_start = NULL};
	b = (t_stack){.top = NULL, .size = 0};
	if (argc < 2)
		ft_exit_error("Push_swap: few arguments", NULL);
	numlist = ft_checkargvs(argc, argv);
	ft_fill_stack(&a, numlist);
	ft_free_matrix(&numlist);
	ft_checker(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
