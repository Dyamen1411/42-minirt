/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:53 by amassias          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:35 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parser_float.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-03-22
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "scene_parser.h"

#include <stdbool.h>
#include <libft.h>

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

char	*parser_next_float(
			char *str,
			float *v
			)
{
	bool	has_int;
	bool	has_dec;
	float	sign;
	float	dec_part;
	size_t	i;

	((void)0, has_int = false, sign = 1.f, i = 0, *v = 0.f, dec_part = 0.f);
	if (*str == '+' || *str == '-')
		((void)0, sign = -1.f, ++str);
	while (ft_isdigit(*str))
		((void)0, has_int = true, *v = 10.f * *v + (float)(*str++ - '0'));
	if (*str++ != '.')
		return (*v *= sign, str - 1);
	while (ft_isdigit(*str))
	{
		((void)0, has_dec = true, ++i);
		dec_part = 10.f * dec_part + (float)(*str++ - '0');
	}
	if (!has_int && !has_dec)
		return (NULL);
	while (i--)
		dec_part /= 10.f;
	return (*v = sign * (*v + dec_part), str);
}
