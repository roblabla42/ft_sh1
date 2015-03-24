/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:01:53 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:15:41 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <libft.h>
#include <stdlib.h>

char		**envcopy(void)
{
	size_t		enviter;
	char		**environcopy;
	extern char	**environ;

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
