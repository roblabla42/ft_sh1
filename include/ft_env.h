/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:29:40 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:31:40 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

char		**envcopy();
/*
** Always returns a malloc'd string, or NULL if none is found
*/
const char	*get_env(char **environ, const char *env);
void		set_env(char ***environ, const char *env, const char *val);
void		unset_env(char ***environ, const char *env);
#endif
