/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_one_at_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:50:48 by falarm            #+#    #+#             */
/*   Updated: 2022/06/25 20:54:03 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	valid_number(char *number, t_data *data, int *result)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (number[0] == '-' && number[1] == '\0')
	{
		free(result);
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
			free_data(data, "Error");
		}
		i++;
	}
}

static int	valid_int(long long check, t_data *data, int *result)
{
	if (check < MIN_INT || check > MAX_INT)
	{
		free(result);
		free_data(data, "Error");
	}
	return ((int) check);
}

int	*parse_one_at_time(int argc, char **argv, t_data *data)
{
	int			*result;
	long long	check;
	int			i;

	i = 1;
	data->size_a = argc - 1;
	result = malloc(sizeof(int) * data->size_a);
	if (!result)
		free_data(data, "Error");
	while (i < argc)
	{
		valid_number(argv[i], data, result);
		check = ft_atoi_long(argv[i]);
		result[i - 1] = valid_int(check, data, result);
		i++;
	}
	return (result);
}
