/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:00:00 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:01:28 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "ft_builtin.h"
#include <libft.h>
#include <stdlib.h>

static t_list	*create_builtin(char *name, t_builtinfunc func)
{
	t_builtin	builtin;

	builtin = (t_builtin){ name, func };
	return (ft_lstnew(&builtin, sizeof(t_builtin)));
}

void			setup_handlers(t_list **builtins)
{
	ft_lstlink(builtins, create_builtin("cd", &builtin_cd));
	ft_lstlink(builtins, create_builtin("setenv", &builtin_setenv));
	ft_lstlink(builtins, create_builtin("unsetenv", &builtin_unsetenv));
	ft_lstlink(builtins, create_builtin("env", &builtin_env));
	ft_lstlink(builtins, create_builtin("exit", &builtin_exit));
}

t_builtinfunc	builtin_handler(char *line)
{
	static t_list		*handlers = NULL;
	char				**cmd;
	t_list				*handlers_iter;

	if (handlers == NULL)
		setup_handlers(&handlers);
	handlers_iter = handlers;
	cmd = ft_strsplit(line, ' ');
	if (cmd[0] == NULL)
		return (NULL);
	while (handlers_iter != NULL &&
			!ft_strequ(((t_builtin*)handlers_iter->content)->name, cmd[0]))
		handlers_iter = handlers_iter->next;
	free(cmd);
	if (handlers_iter == NULL)
		return (NULL);
	else
		return (((t_builtin*)handlers_iter->content)->func);
}

void			run_builtin_handler(t_state *s, t_builtinfunc func, char *line)
{
	char	**argv;
	int		argc;

	argv = ft_strsplit(line, ' ');
	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	func(s, argc - 1, argv);
	argc = 0;
	while (argv[argc] != NULL)
		free(argv[argc++]);
	free(argv);
}
