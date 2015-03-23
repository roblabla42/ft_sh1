/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:14:43 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/10 09:33:34 by roblabla         ###   ########.fr       */
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
