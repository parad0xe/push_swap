/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:04:24 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 18:31:17 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

extern int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && (uint8_t)s1[i] == (uint8_t)s2[i])
		i++;
	return ((uint8_t)s1[i] - (uint8_t)s2[i]);
}
