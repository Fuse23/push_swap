/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:22:22 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 20:24:34 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_data *data, int flag)
{
	if (data->size_a > 1)
		data->stack_a = data->stack_a->next;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int flag)
{
	if (data->size_b > 1)
		data->stack_b = data->stack_b->next;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_data *data, int flag)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		ra(data, 0);
		rb(data, 0);
		if (flag)
			write(1, "rr\n", 3);
	}
}
