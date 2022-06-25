/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:07:23 by falarm            #+#    #+#             */
/*   Updated: 2022/06/25 22:09:56 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft_src/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_lst
{
	int				value;
	int				order;
	int				flag;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_data
{
	int		next;
	int		mid;
	int		max;
	int		min;
	int		size_a;
	int		size_b;
	t_lst	*stack_a;
	t_lst	*stack_b;
}	t_data;

//ft_atoi_long.c
long long	ft_atoi_long(const char *str);

//parse_utils.c
void		free_data(t_data *data, char *output);
void		is_sorted(int *arr, t_data *data);
void		is_duples(int *arr, t_data *data);

//parse_one_at_time.c
int			*parse_one_at_time(int argc, char **argv, t_data *data);

//parse_many_in_one.c
int			*parse_many_in_one(char **argv, t_data *data);

//work_with_stack.c
int			is_stack_sorted(t_data *data);
void		free_stack(t_data *data);
void		lstadd_back(t_lst **stack_a, t_lst *new);
t_lst		*new_list(int value);
void		init_stack_a(int *arr, t_data *data);

//sort_arr.c
void		quick_sort(int *arr, int low, int high);
void		lstiter_order(int *numbers, t_data *data);

void	show(t_data *data);

#endif
