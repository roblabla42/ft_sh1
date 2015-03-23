/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:52:24 by roblabla          #+#    #+#             */
/*   Updated: 2015/02/26 23:42:12 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

typedef struct		s_state
{
	int				running;
	int				return_val;
	char			**env;
}					t_state;

#endif
