/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:07:54 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 12:12:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef struct s_node
{
	t_node	*previous;
	t_node	*next;
	int		value;
}			t_node;

t_node	*node_new(int value);
short	list_front(int value, t_node **root);
short	list_back(int value, t_node **root);
void	list_clear(t_node **root);

#endif
