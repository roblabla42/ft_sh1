/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:03:20 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/10 09:40:08 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

char	**envcopy();
const char	*get_env(char **environ, const char *env);
void		set_env(char ***environ, const char *env, const char *val);
void		unset_env(char ***environ, const char *env);
#endif
