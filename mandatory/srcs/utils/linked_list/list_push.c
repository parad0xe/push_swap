/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:47:53 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/11 16:44:10 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern void	list_push_front(t_node *node, t_node **root)
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

extern void	list_push_back(t_node *node, t_node **root)
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
	}
	return ;
}

extern short	list_push_back_new(int value, t_node **root)
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
		list_push_back(node, root);
	}
	return (1);
}
