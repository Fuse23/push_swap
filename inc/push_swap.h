/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:07:23 by falarm            #+#    #+#             */
/*   Updated: 2022/06/26 22:06:23 by falarm           ###   ########.fr       */
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

//instruction_push.c
void		pa(t_data *data, int flag);
void		pb(t_data *data, int flag);

//instruction_rotate.c
void		ra(t_data *data, int flag);
void		rb(t_data *data, int flag);
void		rr(t_data *data, int flag);

//instruction_reverse.c
void		rra(t_data *data, int flag);
void		rrb(t_data *data, int flag);
void		rrr(t_data *data, int flag);

//instruction_swap.c
void		sa(t_data *data, int flag);
void		sb(t_data *data, int flag);
void		ss(t_data *data, int flag);

//sort_five.c
void		sort_three_a(t_data *data);
void		sort_three_b(t_data *data);
void		sort_five(t_data *data);

//sort_some.c
void		move_down(t_data *data);
void		move_a_to_b_first(t_data *data);
void		min_max_med_a(t_data *data);
void		min_max_med_b(t_data *data);

//sort_big.c
int			search_min_b_to_a(t_data *data);
void		move_b_to_a(t_data *data);
void		move_a_to_b(t_data *data);
void		push_down(t_data *data);
void		search_min_a_to_b(t_data *data);

//sort_optima.c
void		sort_three_a_to_b(t_data *data);
void		privet_norma(t_data *data, int flag);
void		sort_a_to_b_five(t_data *data, int flag, int min, int i);
void		privet_norma_2(t_data *data, int flag);
void		sort_b_to_a_five(t_data *data);


void	show(t_data *data);

#endif
