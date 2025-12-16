/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:10 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/14 12:16:06 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern short	list_push_new(int value, t_node **root)
{
	t_node	*node;

	if (root)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return (0);
		node->value = value;
		node->previous = node;
		node->next = node;
		node->index = 0;
		list_push(node, root);
	}
	return (1);
}
