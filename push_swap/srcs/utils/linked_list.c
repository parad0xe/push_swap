/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:37:10 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 12:26:39 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

short	list_front(int value, t_node **root)
{
	t_node	*node;

	node = node_new(value);
	if (node == NULL)
		return (0);
	if (*root == NULL)
		*root = node;
	else
	{
		node->previous = *root->previous;
		*root->previous = node;
		node->next = *root;
		*root = node;
	}
	return (1);
}

short	list_back(int value, t_node **root)
{
	t_node	*node;

	node = node_new(value);
	if (node == NULL)
		return (0);
	if (*root == NULL)
		*root = node;
	else
	{
		*root->previous->next = node;
		node->previous = *root->previous;
		*root->previous = node;
		node->next = *root;
	}
	return (1);

}

void	list_clear(t_node **root)
{
	t_node	*current;
	t_node	*next;

	next = *root->next;
	while (next != *root)
	{
		current = next;
		next = current->next;
		free(current);
	}
	free(*root);
}
