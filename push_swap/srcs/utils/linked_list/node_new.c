/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:29:41 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 18:26:17 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->previous = node;
	node->next = node;
	return (node);
}
