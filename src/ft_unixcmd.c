/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unixcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:38:55 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:41:54 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <ft_signals.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_env.h"
#include "ft_sh.h"

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

char	*find_command(char **env, char *cmd)
{
	size_t	i;
	char	**paths;

	paths = ft_strsplit(get_env(env, "PATH"), ':');
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
		return ;
	cmd = find_command(state->env, line_split[0]);
	if (cmd == NULL)
	{
		ft_printf("ft_minishell1: command not found: %s\n", line_split[0]);
		return ;
	}
	run_command(cmd, line_split, envcopy());
}
