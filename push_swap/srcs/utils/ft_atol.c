/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:54:12 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 18:35:56 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

extern long	ft_atol(const char *s)
{
	uint64_t	result;
	size_t		i;
	char		sign;

	i = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	sign = 1;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += s[i++] - '0';
	}
	return (result * sign);
}
