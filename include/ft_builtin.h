/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:31:54 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:32:11 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H
# include "ft_sh.h"

typedef void	(*t_builtinfunc)(t_state *, int, char**);

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
