/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_many_in_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:51:17 by falarm            #+#    #+#             */
/*   Updated: 2022/06/25 22:02:24 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	array_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	free_split(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
		free(splits[i++]);
	free(splits);
}

static void	valid_number(char *number, char **splits, t_data *data, int *result)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (number[0] == '-' && number[1] == '\0')
	{
		free(result);
		free_split(splits);
		free_data(data, "Error");
	}
	while (number[i])
	{
		if (number[i] == '-')
			f++;
		if ((!ft_isdigit(number[i]) && number[i] != '-') || f > 1)
		{
			f = 0;
			free(result);
			free_split(splits);
			free_data(data, "Error");
		}
		i++;
	}
}

static int	valid_int(long long check, char **splits, t_data *data, int *result)
{
	if (check < MIN_INT || check > MAX_INT)
	{
		free(result);
		free_split(splits);
		free_data(data, "Error");
	}
	return ((int) check);
}

int	*parse_many_in_one(char **argv, t_data *data)
{
	int			i;
	char		**tmp;
	int			*result;
	long long	check;

	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		free_data(data, "Error");
	data->size_a = array_size(tmp);
	result = malloc(sizeof(int) * data->size_a);
	if (!result)
	{
		free_split(tmp);
		free_data(data, "Error");
	}
	i = 0;
	while (tmp[i])
	{
		valid_number(tmp[i], tmp, data, result);
		check = ft_atoi_long(tmp[i]);
		result[i] = valid_int(check, tmp, data, result);
		i++;
	}
	free_split(tmp);
	return (result);
}
