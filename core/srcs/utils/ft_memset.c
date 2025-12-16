/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:00:09 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:32:09 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

extern void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((uint8_t *)s)[n] = (uint8_t)c;
	return (s);
}
