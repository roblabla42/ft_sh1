/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 14:11:24 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/10 09:32:33 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "ft_env.h"
#include <unistd.h>
#include <ft_printf.h>

int				set_pwd_chdir(char ***environ, const char *cd_to)
{
	char	path[512];

	if (getcwd(path, 512) == NULL)
		return (1);
	else if (chdir(cd_to))
		return (1);
	else
	{
		set_env(environ, "OLDPWD", path);
		if (getcwd(path, 512) != NULL)
			set_env(environ, "PWD", path);
		return (0);
	}
}

void			builtin_cd(t_state *state, int argc, char **argv)
{
	const char	*cd_to;

	(void)state;
	if (argc < 2)
		cd_to = get_env(state->env, "HOME");
	else
		cd_to = argv[1];
	if (access(cd_to, 0 | F_OK) != 0)
		ft_printf("cd: no such file or directory: %s\n", cd_to);
	else if (access(cd_to, 0 | F_OK | R_OK) != 0)
		ft_printf("cd: permission denied: %s\n", cd_to);
	else if (set_pwd_chdir(&state->env, cd_to))
		ft_printf("cd: unknown error\n");
}
