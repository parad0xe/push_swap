/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:39 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 15:05:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

short	list_new_back(int value, t_node **root)
{
	t_node	*node;

	if (root)
	{
		node = node_new(value);
		if (node == NULL)
			return (0);
		list_push_back(node, root);
	}
	return (1);
}
