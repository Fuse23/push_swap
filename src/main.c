/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:38:48 by falarm            #+#    #+#             */
/*   Updated: 2022/06/27 15:32:17 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	*parse(int argc, char **argv, t_data *data)
{
	int	*result;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
		{
			free(data);
			exit(0);
		}
		result = parse_many_in_one(argv, data);
	}
	else
		result = parse_one_at_time(argc, argv, data);
	is_sorted(result, data);
	is_duples(result, data);
	return (result);
}

static t_data	*preparse(int argc, char **argv)
{
	t_data	*data;
	int		*arr;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	arr = parse(argc, argv, data);
	init_stack_a(arr, data);
	data->stack_b = NULL;
	quick_sort(arr, 0, data->size_a - 1);
	lstiter_order(arr, data);
	free(arr);
	return (data);
}

static void	start_sort(t_data *data)
{
	if (is_stack_sorted(data))
		free_stack(data);
	if (data->size_a < 6)
	{
		sort_five(data);
		free_stack(data);
	}
	process_a_first(data);
	while (!(is_stack_sorted(data) && data->size_b == 0))
	{
		if (data->size_b > 0 && data->size_b < 6)
			sort_five_b(data);
		else if (data->size_b >= 6)
			move_to_a(data);
		if (data->size_b == 0)
		{
			sort_five_a(data, 0, 0, 0);
			move_to_b(data);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
	{
		data = preparse(argc, argv);
		start_sort(data);
		free_stack(data);
	}
	return (0);
}
