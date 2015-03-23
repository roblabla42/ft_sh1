/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:45:57 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/23 18:30:06 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "ft_sh.h"
#include "ft_env.h"
#include <ft_printf.h>

void			builtin_unsetenv(t_state *state, int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		unset_env(&state->env, argv[i]);
		i++;
	}
}
