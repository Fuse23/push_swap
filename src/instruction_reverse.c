/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:25:35 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 20:27:12 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_data *data, int flag)
{
	if (data->size_a > 1)
		data->stack_a = data->stack_a->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int flag)
{
	if (data->size_b > 1)
		data->stack_b = data->stack_b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data, int flag)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		rra(data, 0);
		rrb(data, 0);
		if (flag)
			write(1, "rrr\n", 4);
	}
}
