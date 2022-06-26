/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:38:48 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 22:09:38 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push_swap.h"

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

void	show(t_data *data)
{
	t_lst	*tmp;
	int		i;

	tmp = data->stack_a;
	i = 0;
	while (tmp->next != data->stack_a)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\t', 1);
		tmp = tmp->next;
		i++;
	}
	ft_putchar_fd('\n', 1);
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

static void	sorting(t_data *data)
{
	if (is_stack_sorted(data))
		free_stack(data);
	if (data->size_a < 6)
	{
		sort_five(data);
		free_stack(data);
	}
	move_a_to_b_first(data);
	while (!(is_stack_sorted(data) && data->size_b == 0))
	{
		if (data->size_b > 0 && data->size_b < 6)
			sort_b_to_a_five(data);
		else if (data->size_b >= 6)
			move_b_to_a(data);
		if (data->size_b == 0)
		{
			sort_a_to_b_five(data, 0, 0, 0);
			move_a_to_b(data);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
	{
		data = preparse(argc, argv);
		// show(data);
		sorting(data);
		show(data);
		free_stack(data);
	}
	return (0);
}