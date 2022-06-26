/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:36:26 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/26 21:50:01 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_b_to_a(t_data *data)
{
	int	min;

	min = data->stack_a->prev->order + 1;
	if (data->stack_b->order == min)
	{
		pa(data, 1);
		push_down(data);
		return (1);
	}
	else if (data->stack_a->order == min)
		push_down(data);
	else if (data->stack_a->next->order == min)
	{
		sa(data, 1);
		push_down(data);
	}
	return (0);
}

void	move_b_to_a(t_data *data)
{
	int	i;

	min_max_med_b(data);
	i = data->size_b;
	while (i-- > 0)
	{
		if (search_min_b_to_a(data))
			continue ;
		if (data->stack_b->order > data->mid)
		{
			data->stack_b->flag++;
			pa(data, 1);
		}
		else
		{
			data->stack_b->flag++;
			rb(data, 1);
		}
	}
}

void	move_a_to_b(t_data *data)
{
	int	flag;
	int	min;

	flag = data->stack_a->flag;
	while (data->stack_a->flag == flag && flag != -1)
	{
		min = data->stack_a->prev->order + 1;
		if (data->size_b > 1)
			search_min_a_to_b(data);
		if (data->stack_a->order == min)
			push_down(data);
		else
			pb(data, 1);
	}
}

void	push_down(t_data *data)
{
	data->stack_a->flag = -1;
	ra(data, 1);
}

void	search_min_a_to_b(t_data *data)
{
	int	min;

	min = data->stack_a->prev->order + 1;
	if (data->stack_b->order == min)
	{
		pa(data, 1);
		push_down(data);
	}
	else if (data->stack_b->next->order == min)
	{
		sb(data, 1);
		pa(data, 1);
		push_down(data);
	}
	else if (data->stack_b->prev->order == min)
	{
		rrb(data, 1);
		pa(data, 1);
		push_down(data);
	}
	else if (data->stack_a->next->order == min)
	{
		sa(data, 1);
		push_down(data);
	}
}
