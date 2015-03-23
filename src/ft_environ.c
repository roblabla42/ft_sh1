/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:43:17 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/23 19:43:26 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <libft.h>
#include <stdlib.h>

extern char	**environ;

char	**envcopy()
{
	size_t	enviter;
	char	**environcopy;

	enviter = 0;
	while (environ[enviter] != NULL)
		enviter++;
	environcopy = (char**)malloc(sizeof(char*) * (enviter + 1));
	enviter = 0;
	while (environ[enviter] != NULL)
	{
		environcopy[enviter] = ft_strdup(environ[enviter]);
		enviter++;
	}
	environcopy[enviter] = NULL;
	return (environcopy);
}

/*
 * Always returns a malloc'd string, or NULL if none is found
 */
const char	*get_env(char **environ, const char *env)
{
	size_t	i;
	char	*enveq;

	i = 0;
	enveq = ft_strjoin(env, "=");
	while (environ[i] != NULL && !ft_strprefix(environ[i], enveq))
		i++;
	free(enveq);
	if (environ[i] == NULL)
		return (NULL);
	else
		return (ft_strdup(ft_strchr(environ[i], '=') + 1));
}

void		set_env(char ***environ, const char *env, const char *val)
{
	size_t	i;
	char	**newenv;

	i = 0;
	env = ft_strjoin(env, "=");
	while ((*environ)[i] != NULL && !ft_strprefix((*environ)[i], env))
		i++;
	if ((*environ)[i] == NULL)
	{
		// i is the size !
		newenv = malloc(sizeof(char*) * (i + 2));
		ft_memcpy(newenv, *environ, sizeof(char*) * i);
		newenv[i] = ft_strjoin(env, val);
		newenv[i + 1] = NULL;
		free(*environ);
		*environ = newenv;
	}
	else
	{
		free((*environ)[i]);
		(*environ)[i] = ft_strjoin(env, val);
	}
	free((char*)env);
}

void		unset_env(char ***environ, const char *env, const char *val)
{
	size_t	i;

	(void)val;
	i = 0;
	env = ft_strjoin(env, "=");
	while ((*environ)[i] != NULL && !ft_strprefix((*environ)[i], env))
		i++;
	while ((*environ)[i] != NULL)
	{
		(*environ)[i] = (*environ)[i + 1];
		i++;
	}
	free((char*)env);
}
