/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:07:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 17:50:10 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*previous;
	struct s_node	*next;
	int				value;
}			t_node;

t_node	*node_new(int value);
t_node	*list_pop(t_node **node);

void	list_push(t_node *node, t_node **root);
short	list_push_new(int value, t_node **root);

void	list_clear(t_node **root);

#endif
