/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:57:14 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 19:57:15 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "ft_sh.h"

void			builtin_exit(t_state *state, int argc, char **argv)
{
	if (argc < 2)
	{
		state->running = 0;
		state->return_val = 0;
	}
	else if (argc < 3)
	{
		state->running = 0;
		state->return_val = ft_atoi(argv[1]);
	}
	else
		ft_printf("exit: too many arguments\n");
}
