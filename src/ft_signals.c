/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 20:32:17 by rlambert          #+#    #+#             */
/*   Updated: 2015/03/24 20:32:18 by rlambert         ###   ########.fr       */
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
