/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:05:53 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 14:43:58 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

int	ft_min4(int one, int two, int three, int four)
{
	int	output;

	output = one;
	if (output > two)
	{
		output = two;
	}
	if (output > three)
	{
		output = three;
	}
	if (output > four)
	{
		output = four;
	}
	return (output);
}
