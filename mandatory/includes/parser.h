/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:33:34 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 11:37:56 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define HASH_SIZE 0x10000

typedef enum e_errcode
{
	NOERR,
	ERR_AC,
	ERR_STRING,
	ERR_NOT_INT,
	ERR_ALLOC,
	ERR_DUPLICATA,
}	t_errcode;

void	parse(size_t ac, char **av, t_info *info, t_stack *stack);

#endif
