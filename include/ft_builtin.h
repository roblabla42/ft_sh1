/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 18:03:57 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/02 15:30:09 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H
# include "ft_sh.h"

typedef void (*t_builtinfunc)(t_state *, int, char**);

typedef struct	s_builtin
{
	char			*name;
	t_builtinfunc	func;
}				t_builtin;

t_builtinfunc	builtin_handler(char *line);
void			run_builtin_handler(t_state *s, t_builtinfunc func, char *line);
void			builtin_cd(t_state *state, int argc, char **argv);
void			builtin_env(t_state *state, int argc, char **argv);
void			builtin_exit(t_state *state, int argc, char **argv);
void			builtin_setenv(t_state *state, int argc, char **argv);
void			builtin_unsetenv(t_state *state, int argc, char **argv);

#endif
