/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:23:06 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/23 18:57:52 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "ft_env.h"
#include "ft_signals.h"
#include "ft_builtin.h"

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

int		command_in_path(char *dir, char *cmd)
{
	char		*path;
	int			retval;

	if (ft_strsuffix(dir, "/"))
		path = ft_strjoin(dir, cmd);
	else
		path = ft_multistrjoin(3, dir, "/", cmd);
	retval = access(path, 0 | F_OK | X_OK);
	free(path);
	return (retval == 0);
}

/*
 ** Returned string has been malloc'd and MUST be freed (unless NULL)
 */
char	*find_command(char **env, char *cmd)
{
	size_t	i;

	char **paths = ft_strsplit(get_env(env, "PATH"), ':');
	// TODO : Free paths
	i = 0;
	while (paths[i] != NULL && !command_in_path(paths[i], cmd))
		i++;
	if (paths[i] != NULL)
	{
		if (ft_strsuffix(paths[i], "/"))
			return (ft_strjoin(paths[i], cmd));
		else
			return (ft_multistrjoin(3, paths[i], "/", cmd));
	}
	else
	{
		if (access(cmd, 0 | F_OK | X_OK) == 0)
			return (cmd);
		else
			return (NULL);
	}
}

void	run_command(char *cmd, char **argv, char **envp)
{
	pid_t	pid;
	int		child_status;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, argv, envp);
		ft_printf("EXECVE ERROR\n");
		exit(0);
	}
	else
	{
		while (waitpid(pid, &child_status, WNOHANG) == 0)
			if (has_signal(SIGINT))
				kill(pid, consume_signal(SIGINT));
	}
}

void	unix_handler(t_state *state, char *line)
{
	char	**line_split;
	char	*cmd;

	line_split = ft_strsplitwith(line, " \t", NULL);
	if (line_split[0] == NULL)
		return;
	cmd = find_command(state->env, line_split[0]);
	if (cmd == NULL)
	{
		ft_printf("ft_minishell1: command not found: %s\n", line_split[0]);
		return;
	}
	run_command(cmd, line_split, envcopy());
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
