/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:59:43 by falarm            #+#    #+#             */
/*   Updated: 2022/06/25 21:39:38 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack_a(int *arr, t_data *data)
{
	int		i;
	t_lst	*list;
	t_lst	*tmp;

	i = 0;
	list = NULL;
	while (i < data->size_a)
	{
		tmp = new_list(arr[i]);
		if (!tmp)
		{
			free_stack(data);
			return ;
		}
		lstadd_back(&list, tmp);
		tmp = NULL;
		i++;
	}
	data->stack_a = list;
}

t_lst	*new_list(int value)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (list == NULL)
		return (NULL);
	list->value = value;
	list->flag = 0;
	list->order = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	lstadd_back(t_lst **stack_a, t_lst *new)
{
	t_lst	*begin;

	if (new == NULL)
		return ;
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = new;
			new->prev = begin->prev;
			new->next = begin;
			begin->prev = new;
		}
		else
		{
			begin->prev = new;
			begin->next = new;
			new->prev = begin;
			new->next = begin;
		}
	}
	else
		*stack_a = new;
	return ;
}

void	free_stack(t_data *data)
{
	t_lst	*tmp;

	while (data->size_a--)
	{
		tmp = data->stack_a->next;
		free(data->stack_a);
		data->stack_a = NULL;
		data->stack_a = tmp;
	}
	while (data->size_b--)
	{
		tmp = data->stack_b->next;
		free(data->stack_b);
		data->stack_b = NULL;
		data->stack_b = tmp;
	}
	free(data);
	exit(0);
}

int	is_stack_sorted(t_data *data)
{
	t_lst	*tmp;
	int		i;

	tmp = data->stack_a;
	i = data->size_a - 1;
	while (i-- > 0)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
