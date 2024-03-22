/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:45:05 by amassias          #+#    #+#             */
/*   Updated: 2024/03/22 11:56:37 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file update.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-03-22
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/window.h"

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	window_set_update_hook(
			t_window_ctx *ctx,
			t_update_hook hook,
			void *ptr
			)
{
	__window_set_hook(ctx, __HOOK__UPDATE, (void *)hook, ptr);
}