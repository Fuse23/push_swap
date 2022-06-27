/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:30:56 by falarm            #+#    #+#             */
/*   Updated: 2022/06/27 14:03:48 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three_a(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->order;
	b = data->stack_a->next->order;
	c = data->stack_a->prev->order;
	if (b > a && b > c)
		rra(data, 1);
	else if (a > b && a > c)
		ra(data, 1);
	a = data->stack_a->order;
	b = data->stack_a->next->order;
	if (a > b)
		sa(data, 1);
}

int	short_way(t_data *data)
{
	int		i;
	int		j;
	t_lst	*tmp;

	tmp = data->stack_a;
	i = 0;
	while (++i)
	{
		if (tmp->order == data->min)
			break ;
		tmp = tmp->next;
	}
	tmp = data->stack_a;
	j = 0;
	while (++j)
	{
		if (tmp->order == data->min)
			break ;
		tmp = tmp->prev;
	}
	if (j >= i)
		return (1);
	return (0);
}

void	sort_five(t_data *data)
{
	while (data->size_a > 3)
	{
		value_in_a(data);
		if (data->stack_a->order == data->min)
		{
			pb(data, 1);
			continue ;
		}
		if (short_way(data))
			ra(data, 1);
		else
			rra(data, 1);
	}
	sort_three_a(data);
	pa(data, 1);
	pa(data, 1);
}
