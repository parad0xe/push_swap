/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:10 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 17:54:34 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern short	list_push_new(int value, t_node **root)
{
	t_node	*node;

	if (root)
	{
		node = node_new(value);
		if (node == NULL)
			return (0);
		list_push(node, root);
	}
	return (1);
}
