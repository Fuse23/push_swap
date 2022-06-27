/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optima.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:57:33 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/27 13:46:31 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three_in_b(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (data->size_b == 0)
		return ;
	a = data->stack_b->order;
	b = data->stack_b->next->order;
	c = data->stack_b->prev->order;
	if (b > a && b > c)
		rrb(data, 1);
	else if (a > b && a > c)
		rb(data, 1);
	a = data->stack_b->order;
	b = data->stack_b->next->order;
	if (a > b)
		sb(data, 1);
}

static void	sort_five_next_a(t_data *data, int flag)
{
	sort_three_in_b(data);
	if (data->stack_a->order > data->stack_a->next->order && \
		data->stack_a->flag == data->stack_a->next->flag)
		sa(data, 1);
	while (data->size_b != 0)
	{
		if (data->stack_a->order > data->stack_b->order || \
			data->stack_a->flag != flag)
		{
			pa(data, 1);
			push_down(data);
		}
		else
			push_down(data);
	}
	while (data->stack_a->flag == flag && flag != -1)
		push_down(data);
}

void	sort_five_a(t_data *data, int flag, int min, int i)
{
	t_lst	*tmp;

	min = data->stack_a->prev->order + 1;
	flag = data->stack_a->flag;
	tmp = data->stack_a;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i > 2)
		{
			if (data->stack_a->order == min)
			{
				push_down(data);
				min++;
			}
			else
				pb(data, 1);
			i--;
		}
		sort_five_next_a(data, flag);
	}
}

static void	sort_five_next_b(t_data *data, int flag)
{
	sort_three_in_b(data);
	if (data->stack_a->order > data->stack_a->next->order && \
		data->stack_a->flag == data->stack_a->next->flag)
		sa(data, 1);
	while (data->size_b != 0)
	{
		if (data->stack_a->order > data->stack_b->order || \
			data->stack_a->flag == -1)
		{
			pa(data, 1);
			push_down(data);
		}
		else
			push_down(data);
	}
	while (data->stack_a->flag == flag && flag != -1 && \
			data->stack_a->order +1 == data->stack_a->prev->order)
		push_down(data);
}

void	sort_five_b(t_data *data)
{
	int		flag;
	int		min;
	int		i;

	i = data->size_b;
	min = data->stack_a->prev->order + 1;
	flag = data->stack_a->flag;
	while (i > 3)
	{
		if (data->stack_b->order == min)
		{
			pa(data, 1);
			push_down(data);
			min++;
		}
		else
			pa(data, 1);
		i--;
	}
	sort_five_next_b(data, flag);
}
