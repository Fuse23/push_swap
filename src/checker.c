/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:38:27 by falarm            #+#    #+#             */
/*   Updated: 2022/06/27 17:56:52 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	instructions(char *line, t_data *data)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(data, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(data, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(data, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(data, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(data, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(data, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(data, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(data, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(data, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(data, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(data, 0);
	else
		return (1);
	return (0);
}

static void	check(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (instructions(line, data))
		{
			free(line);
			ft_putendl_fd("Error", 2);
			return ;
		}
		free(line);
	}
	if (data->stack_b == NULL && is_stack_sorted(data))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
	{
		data = preparse(argc, argv);
		check(data);
		free_stack(data);
	}
}
