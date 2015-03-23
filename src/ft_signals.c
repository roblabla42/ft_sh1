/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 09:59:46 by roblabla          #+#    #+#             */
/*   Updated: 2015/03/20 17:12:27 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_signals.h"

t_list *g_signals = NULL;

int		has_signal(int type)
{
	t_list	*signals;

	signals = g_signals;
	while (signals != NULL && *(int*)signals->content != type)
		signals = signals->next;
	if (signals == NULL)
		return (0);
	else
		return (1);
}

int		consume_signal(int type)
{
	t_list	*signals;
	t_list	*prev_signals;

	prev_signals = NULL;
	signals = g_signals;
	while (signals != NULL && *(int*)signals->content != type)
	{
		prev_signals = signals;
		signals = signals->next;
	}
	if (signals == NULL)
		return (-1);
	else
	{
		if (prev_signals != NULL)
		{
			prev_signals->next = signals->next;
			ft_lstdelone(&signals, NULL);
		}
		else
			ft_lstdelone(&g_signals, NULL);
		return (type);
	}
}
