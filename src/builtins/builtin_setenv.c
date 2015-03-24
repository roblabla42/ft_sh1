/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:58:10 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 19:59:29 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include "ft_env.h"
#include "ft_builtin.h"
#include "ft_sh.h"

/*
** TODO : too many arguments
*/
void			builtin_setenv(t_state *state, int argc, char **argv)
{
	if (argc == 3)
		set_env(&state->env, argv[1], argv[2]);
	else if (argc == 2)
		set_env(&state->env, argv[1], "");
	else if (argc == 1)
		builtin_env(state, 0, NULL);
	else if (argc > 3)
		ft_printf("setenv: too many arguments ???\n");
}
