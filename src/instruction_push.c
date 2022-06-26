/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:15:27 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 20:21:11 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_b(t_data *data)
{
	t_lst	*tmp;

	tmp = data->stack_a->next;
	data->stack_a->prev->next = data->stack_a->next;
	data->stack_a->next->prev = data->stack_a->prev;
	if (data->stack_b)
	{
		data->stack_a->prev = data->stack_b->prev;
		data->stack_a->next = data->stack_b;
		data->stack_b->prev->next = data->stack_a;
		data->stack_b->prev = data->stack_a;
		data->stack_b = data->stack_a;
	}
	else
	{
		data->stack_b = data->stack_a;
		data->stack_a->next = data->stack_b;
		data->stack_a->prev = data->stack_b;
	}
	data->stack_a = tmp;
}

void	push_a(t_data *data)
{
	t_lst	*tmp;

	tmp = data->stack_b->next;
	data->stack_b->prev->next = data->stack_b->next;
	data->stack_b->next->prev = data->stack_b->prev;
	if (data->stack_a)
	{
		data->stack_b->prev = data->stack_a->prev;
		data->stack_b->next = data->stack_a;
		data->stack_a->prev->next = data->stack_b;
		data->stack_a->prev = data->stack_b;
		data->stack_a = data->stack_b;
	}
	else
	{
		data->stack_a = data->stack_b;
		data->stack_a->next = data->stack_a;
		data->stack_a->prev = data->stack_a;
	}
	data->stack_b = tmp;
}

void	pb(t_data *data, int flag)
{
	if (data->size_a == 0)
		return ;
	push_b(data);
	if (data->size_a == 1)
		data->stack_a = NULL;
	data->size_b++;
	data->size_a--;
	if (flag)
		write(1, "pb\n", 3);
}

void	pa(t_data *data, int flag)
{
	if (data->size_b == 0)
		return ;
	push_a(data);
	if (data->size_b == 1)
		data->stack_b = NULL;
	data->size_b--;
	data->size_a++;
	if (flag)
		write(1, "pa\n", 3);
}
