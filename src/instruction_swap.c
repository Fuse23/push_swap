/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:02:20 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 22:05:48 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_data *data, int flag)
{
	int	tmp;

	if (data->size_a < 2)
		return ;
	tmp = data->stack_a->value;
	data->stack_a->value = data->stack_a->next->value;
	data->stack_a->next->value = tmp;
	tmp = data->stack_a->order;
	data->stack_a->order = data->stack_a->next->order;
	data->stack_a->next->order = tmp;
	tmp = data->stack_a->flag;
	data->stack_a->flag = data->stack_a->next->flag;
	data->stack_a->next->flag = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int flag)
{
	int	tmp;

	if (data->size_b < 2)
		return ;
	tmp = data->stack_b->value;
	data->stack_b->value = data->stack_b->next->value;
	data->stack_b->next->value = tmp;
	tmp = data->stack_b->order;
	data->stack_b->order = data->stack_b->next->order;
	data->stack_b->next->order = tmp;
	tmp = data->stack_b->flag;
	data->stack_b->flag = data->stack_b->next->flag;
	data->stack_b->next->flag = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_data *data, int flag)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		sa(data, 0);
		sb(data, 0);
		if (flag)
			write(1, "ss\n", 3);
	}
}

