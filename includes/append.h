/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:49:08 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/12 19:09:50 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPEND_H
# define APPEND_H

# include "libft.h"

bool	append_char(t_buff *buff, char c);
bool	append_int(t_buff *buff, int nb);
bool	append_uint(t_buff *buff, unsigned int nb);
bool	append_hex(t_buff *buff, unsigned long nb, bool uppercase);
bool	append_ptr(t_buff *buff, unsigned long nb);

#endif
