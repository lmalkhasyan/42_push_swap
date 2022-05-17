/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:30:58 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/15 13:13:53 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_checkdubles(char **nums, int i, int k)
{
	int	j;
	int	m;

	while (nums[i] != NULL)
	{
		j = i + 1;
		while (nums[j] != NULL)
		{
			k = 0;
			m = 0;
			while (nums[i][k] == '0' || nums[i][k] == '+' || nums[i][k] == '-')
				k++;
			while (nums[j][m] == '0' || nums[j][m] == '+' || nums[j][m] == '-')
				m++;
			if (nums[j][m] == '\0' && nums[i][k] == '\0')
				ft_exit_error("Push_swap: Dublicate Numbers in input", nums);
			if (((nums[i][0] == '-' && nums[j][0] != '-')
				|| (nums[i][0] != '-' && nums[j][0] == '-')))
				break ;
			if (ft_strcmp(&nums[i][k], &nums[j][m]) == 0)
				ft_exit_error("Push_swap: Dublicate Numbers in input", nums);
			j++;
		}
		i++;
	}
}

static void	ft_maxmint(char **nums)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (nums[i] != NULL)
	{
		j = 0;
		sign = 1;
		if (nums[i][j] == '-')
			sign = -1;
		while (nums[i][j] == '0' || nums[i][j] == '+' || nums[i][j] == '-')
			j++;
		if (ft_strlen(&nums[i][j]) > 10)
			ft_exit_error("Push_swap: Number not in a range INT", nums);
		if ((ft_strlen(&nums[i][j]) == 10)
			&& ((sign == 1 && ft_strcmp("2147483647", &nums[i][j]) < 0)
			|| (sign == -1 && ft_strcmp("2147483648", &nums[i][j]) < 0)))
			ft_exit_error("Push_swap: Number not in a range INT", nums);
		i++;
	}
}

static void	ft_check_nums(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i] != NULL)
	{
		j = 0;
		if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (nums[i][j] >= '0' && nums[i][j] <= '9')
			j++;
		if (nums[i][j] != '\0')
			ft_exit_error("Push_swap: Input symbol error", nums);
		i++;
	}
}

char	**ft_checkargvs(int argc, char *argv[])
{
	char	*nums;
	char	**numbers;
	int		i;

	i = 1;
	nums = NULL;
	while (i < argc)
	{
		nums = ft_strjoin(nums, argv[i]);
		nums = ft_strjoin(nums, " ");
		i++;
	}
	numbers = ft_split(nums, ' ');
	ft_free_array(&nums);
	if (*numbers == '\0')
	{
		ft_free_matrix(&numbers);
		exit(EXIT_SUCCESS);
	}
	ft_check_nums(numbers);
	ft_maxmint(numbers);
	ft_checkdubles(numbers, 0, 0);
	return (numbers);
}
