/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:59:54 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 19:59:54 by rlambert         ###   ########.fr       */
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
