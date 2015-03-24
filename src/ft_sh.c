/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:33:34 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:45:23 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "ft_env.h"
#include "ft_signals.h"
#include "ft_builtin.h"
#include "ft_unixcmd.h"

#include <ft_printf.h>
#include <libft.h>
#include <get_next_line.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <signal.h>

void	show_prompt(t_state *state)
{
	ft_printf("%s$> ", get_env(state->env, "PWD"));
}

void	handle_cmd(t_state *state, char *line)
{
	char		**cmds;
	size_t		i;

	cmds = ft_strsplit(line, ';');
	i = 0;
	while (cmds[i] != NULL)
	{
		if (builtin_handler(cmds[i]) != NULL)
			run_builtin_handler(state, builtin_handler(cmds[i]), cmds[i]);
		else
			unix_handler(state, cmds[i]);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	setup(t_state *state)
{
	char	buf[MAXPATHLEN];

	state->running = 1;
	state->return_val = 0;
	state->env = envcopy();
	set_env(&state->env, "PWD", getcwd(buf, MAXPATHLEN));
	set_env(&state->env, "OLDPWD", getcwd(buf, MAXPATHLEN));
}

void	handle_sigint(int sig)
{
	ft_lstadd(&g_signals, &sig, sizeof(4));
}

int		main(void)
{
	t_state		state;
	char		*line;
	int			ret;

	signal(SIGINT, handle_sigint);
	setup(&state);
	while (state.running)
	{
		show_prompt(&state);
		ret = get_next_line(0, &line);
		if (ret > 0)
		{
			handle_cmd(&state, line);
			free(line);
		}
		else
			state.running = 0;
	}
	return (state.return_val);
}
