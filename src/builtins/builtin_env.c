/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:19:06 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/20 16:45:41 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <sys/types.h>
#include <ft_printf.h>
#include <stdlib.h>

void			builtin_env(t_state *state, int argc, char **argv)
{
	size_t		i;

	(void)argc;
	(void)argv;
	i = 0;
	while (state->env[i] != NULL)
		ft_printf("%s\n\x1b[39;49m", state->env[i++]);
}
