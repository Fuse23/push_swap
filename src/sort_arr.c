/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:12:49 by falarm            #+#    #+#             */
/*   Updated: 2022/06/25 22:26:02 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	j = low;
	pivot = arr[high];
	i = (low - 1);
	while (j <= high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void	lstiter_order(int *numbers, t_data *data)
{
	int		i;
	int		j;
	t_lst	*tmp;

	i = 0;
	tmp = data->stack_a;
	while (i < data->size_a)
	{
		j = 0;
		while (j < data->size_a)
		{
			if (numbers[i] == tmp->value && tmp->order == 0)
			{
				tmp->order = i + 1;
				break ;
			}
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}
