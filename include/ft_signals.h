/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:28:49 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:29:04 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H
# include <libft.h>

extern t_list	*g_signals;

int		consume_signal(int type);
int		has_signal(int type);

#endif
