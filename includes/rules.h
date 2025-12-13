/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:21:21 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/13 03:05:39 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "libft.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_rules
{
	bool	plus;
	bool	space;
	bool	hex_prefix;
	bool	zero_padding;
	bool	right_padding;
	int		precision;
	bool	width_enabled;
	int		width;
	char	conversion;
	bool	is_zero;
}	t_rules;

void	rules_parse(t_rules *rules, const char **fstring);
bool	rules_apply(t_buff *buff, t_rules *rules);

#endif
