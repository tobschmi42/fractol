/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobschmi <tobschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:54:32 by tobschmi          #+#    #+#             */
/*   Updated: 2026/04/28 23:04:57 by tobschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_controller(int keypress, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keypress == SCROLL_UP)
		data->image_data.zoom += 0.2;
	else if (keypress == SCROLL_DOWN)
		data->image_data.zoom -= 0.2;
	return (0);
}

int	key_controller(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_img(data);
	return (0);
}
