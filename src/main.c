/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:08:07 by amassias          #+#    #+#             */
/*   Updated: 2024/03/26 17:41:00 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-03-21
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "renderer.h"

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <unistd.h>

#include <math.h>
#include <libft.h>
#include "utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static void				_show_help(
							int fd,
							const char *pn
							);

noreturn static void	_quit_no_cleanup(
							const char *pn,
							const char *message,
							int fd,
							int code
							);

static bool				_quit_on_q(
							int keycode,
							t_window_ctx *ctx
							);

static bool				_render(
							t_minirt_ctx *ctx
							);

/* ************************************************************************** */
/*                                                                            */
/* Main                                                                       */
/*                                                                            */
/* ************************************************************************** */

int	main(
		int argc,
		char **argv
		)
{
	static t_minirt_ctx	ctx = {0};

	if (argc < 2)
		_quit_no_cleanup(argv[0], "Missing scene file.", STDERR_FILENO, 1);
	if (argc > 2)
		_quit_no_cleanup(argv[0], "Too many arguments.", STDERR_FILENO, 1);
	if (scene_load(&ctx.scene, argv[1]) == NULL)
	{
		scene_cleanup(&ctx.scene);
		_quit_no_cleanup(argv[0], "", STDERR_FILENO, 1);
	}
	if (window_initialize(&ctx.window) == NULL)
	{
		scene_cleanup(&ctx.scene);
		_quit_no_cleanup(argv[0], "", STDERR_FILENO, 1);
	}
	window_set_key_hook(&ctx.window, (t_key_hook)_quit_on_q, &ctx.window);
	window_set_render_hook(&ctx.window, (t_render_hook)_render, &ctx);
	window_run(&ctx.window);
	scene_cleanup(&ctx.scene);
	window_cleanup(&ctx.window);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static void	_show_help(
				int fd,
				const char *pn
				)
{
	dprintf(fd, "Usage: %s [FILE]\n", pn);
}

noreturn static void	_quit_no_cleanup(
							const char *pn,
							const char *message,
							int fd,
							int code
							)
{
	if (*message != '\0')
		dprintf(fd, "%s\n", message);
	_show_help(fd, pn);
	exit(code);
}

static bool	_quit_on_q(
				int keycode,
				t_window_ctx *ctx
				)
{
	(void)ctx;
	if (keycode == 'q')
		return (true);
	return (false);
}

static bool	_render(
				t_minirt_ctx *ctx
				)
{
	render_scene(&ctx->scene, &ctx->window.frame_buffer);
	return (false);
}
