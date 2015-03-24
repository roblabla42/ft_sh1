/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:57:03 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 19:57:03 by rlambert         ###   ########.fr       */
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
