/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:28:19 by ale-boud          #+#    #+#             */
/*   Updated: 2024/03/22 11:23:57 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file camera.h
 * @author ale-boud (ale-boud@student.42lehavre.fr)
 * @brief Camera definition.
 * @date 2024-03-21
 * @copyright Copyright (c) 2024
 */

#ifndef CAMERA_H
# define CAMERA_H

// ************************************************************************** //
// *                                                                        * //
// * Includes                                                               * //
// *                                                                        * //
// ************************************************************************** //

# include "../mathrt.h"

// ************************************************************************** //
// *                                                                        * //
// * Structure definition                                                   * //
// *                                                                        * //
// ************************************************************************** //

typedef struct s_camera
{
	t_point3	position;
	t_vector3	orientation;
	float		fov;
}	t_camera;

#endif
