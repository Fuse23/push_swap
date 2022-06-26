/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:30:56 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 22:01:26 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_a(t_data *data)
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

void	sort_three_b(t_data *data)
{
	int	a;
	int	b;
	int	c;
	int	i;

	a = data->stack_b->order;
	b = data->stack_b->next->order;
	c = data->stack_b->prev->order;
	i = data->size_b;
	if (b > a && b > c)
		rrb(data, 1);
	else if (a > b && a > c)
		rb(data, 1);
	a = data->stack_b->order;
	b = data->stack_b->next->order;
	if (a > b)
		sb(data, 1);
	while (i-- > 0)
	{
		data->stack_b->flag = -1;
		pa(data, 1);
		ra(data, 1);
	}
}

int	short_cut(t_data *data)
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
		min_max_med_a(data);
		if (data->stack_a->order == data->min)
		{
			pb(data, 1);
			continue ;
		}
		if (short_cut(data))
			ra(data, 1);
		else
			rra(data, 1);
	}
	sort_three_a(data);
	pa(data, 1);
	pa(data, 1);
}
