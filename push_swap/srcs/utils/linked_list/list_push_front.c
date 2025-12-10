/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:47:53 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 17:07:09 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	list_push_front(t_node *node, t_node **root)
{
	if (!root || !node)
		return ;
	if (*root == NULL)
		*root = node;
	else
	{
		(*root)->previous->next = node;
		node->previous = (*root)->previous;
		(*root)->previous = node;
		node->next = *root;
		*root = node;
	}
	return ;
}
