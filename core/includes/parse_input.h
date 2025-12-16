/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:33:34 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:33:55 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include <limits.h>
# include "core.h"
# include "utils.h"
# include "linked_list.h"

# define HASH_SIZE 0x10000

typedef enum e_errcode
{
	NOERR,
	ERR_AC,
	ERR_ALLOC,
	ERR_STRING,
	ERR_NOT_INT,
	ERR_DUPLICATA,
	ERR_INSTRUCTION
}	t_errcode;

void	parse_input(size_t ac, char **av, t_info *info, t_stack *stack);

#endif
