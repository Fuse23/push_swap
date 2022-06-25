/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:54:35 by falarm            #+#    #+#             */
/*   Updated: 2022/06/25 20:55:16 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_data(t_data *data, char *output)
{
	free(data);
	ft_putendl_fd(output, 2);
	exit(0);
}

void	is_sorted(int *arr, t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->size_a - 1))
	{
		if (arr[i] > arr[i + 1])
			return ;
		i++;
	}
	free(arr);
	free(data);
	exit(0);
}

void	is_duples(int *arr, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a - 1)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				free_data(data, "Error");
			}
			j++;
		}
		i++;
	}
}
