/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_some.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:38:08 by falarm            #+#    #+#             */
/*   Updated: 2022/06/27 13:55:51 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_down_from_b(t_data *data)
{
	while (data->stack_b->prev->flag == -1)
		rrb(data, 1);
	while (data->stack_b->flag == -1)
	{
		pa(data, 1);
		ra(data, 1);
	}
}

void	process_a_first(t_data *data)
{
	int	i;

	value_in_a(data);
	i = data->size_a;
	while (i-- > 0)
	{
		if (data->stack_a->order <= data->mid)
		{
			pb(data, 1);
			if (data->stack_b->order == data->min)
			{
				data->stack_b->flag = -1;
				rb(data, 1);
			}
		}
		else
		{
			if (data->size_b == data->max - data->mid + 1)
				break ;
			else
				ra(data, 1);
		}
	}
	push_down_from_b(data);
}

void	value_in_a(t_data *data)
{
	int	i;
	int	min;
	int	max;

	if (data->size_a == 0)
		return ;
	i = data->size_a;
	min = data->stack_a->order;
	max = data->stack_a->order;
	while (i-- > 0)
	{
		if (min > data->stack_a->order)
			min = data->stack_a->order;
		if (max < data->stack_a->order)
			max = data->stack_a->order;
		data->stack_a = data->stack_a->next;
	}
	data->min = min;
	data->max = max;
	data->mid = (min + max) / 2;
}

void	value_in_b(t_data *data)
{
	int	i;
	int	min;
	int	max;

	if (data->size_b == 0)
		return ;
	i = data->size_b;
	min = data->stack_b->order;
	max = data->stack_b->order;
	while (i-- > 0)
	{
		if (min > data->stack_b->order)
			min = data->stack_b->order;
		if (max < data->stack_b->order)
			max = data->stack_b->order;
		data->stack_b = data->stack_b->next;
	}
	data->max = max;
	data->mid = (min + max) / 2;
}
