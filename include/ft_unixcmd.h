/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unixcmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:42:14 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 21:05:55 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNIXCMD_H
# define FT_UNIXCMD_H

int		command_in_path(char *dir, char *cmd);
char	*find_command(char **env, char *cmd);
void	run_command(char *cmd, char **argv, char **envp);
void	unix_handler(t_state *state, char *line);

#endif
