/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:48:41 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 16:53:42 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	list_push_back(t_node *node, t_node **root)
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
