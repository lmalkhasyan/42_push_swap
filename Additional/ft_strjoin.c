/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:47:55 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/04 16:48:59 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc(s1_len + s2_len + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	if (s1)
		free(s1);
	return (strjoin);
}
