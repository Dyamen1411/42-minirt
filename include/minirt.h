/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:18:20 by amassias          #+#    #+#             */
/*   Updated: 2024/03/22 09:26:25 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file minirt.h
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-03-19
 * @copyright Copyright (c) 2024
 */

#ifndef MINIRT_H
# define MINIRT_H

// ************************************************************************** //
// *                                                                        * //
// * Includes                                                               * //
// *                                                                        * //
// ************************************************************************** //

# include "scene.h"
# include "graphics/window.h"

// ************************************************************************** //
// *                                                                        * //
// * Structure definition                                                   * //
// *                                                                        * //
// ************************************************************************** //

typedef struct s_minirt_ctx
{
	t_scene			scene;
	t_window_ctx	window;
}	t_minirt_ctx;

/* ************************************************************************** */
/*                                                                            */
/* Header prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

#endif