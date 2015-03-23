/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:48:02 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/20 14:46:36 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

#include <libft.h>

extern t_list	*g_signals;

int		consume_signal(int type);
int		has_signal(int type);

#endif
