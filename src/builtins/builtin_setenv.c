/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:16:31 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/10 09:35:38 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include "ft_env.h"
#include "ft_builtin.h"
#include "ft_sh.h"

void			builtin_setenv(t_state *state, int argc, char **argv)
{
	if (argc == 3)
		set_env(&state->env, argv[1], argv[2]);
	else if (argc == 2)
		set_env(&state->env, argv[1], "");
	else if (argc == 1)
		builtin_env(state, 0, NULL);
	else if (argc > 3)
		ft_printf("setenv: too many arguments ???\n"); // TODO
}
