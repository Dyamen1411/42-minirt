/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:20 by amassias          #+#    #+#             */
/*   Updated: 2024/04/11 15:13:32 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ambiant.c
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

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

#define RATIO 0
#define COLOR 1

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

bool	element_acceptor__ambient_light(
			t_scene *scene,
			t_token tokens[]
			)
{
	if (scene->_has_ambiant)
		return (false);
	scene->ambient.color.r = tokens[COLOR].color.r * tokens[RATIO].fp;
	scene->ambient.color.g = tokens[COLOR].color.g * tokens[RATIO].fp;
	scene->ambient.color.b = tokens[COLOR].color.b * tokens[RATIO].fp;
	scene->_has_ambiant = true;
	return (true);
}
