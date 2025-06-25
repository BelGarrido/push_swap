/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:56:04 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/25 12:15:37 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h> // size_t
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <fcntl.h>  // flags open
# include <stdio.h> // printf
# include <limits.h> // INT_MAX & MIN
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				below_med;
	int				is_big;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//specific functions

int		ft_valid_arguments(int argc, char *argv[]);
int		ft_is_valid_number(char *argument);
void	ft_putstr_fd(char *s, int fd);

/* ARGUMENTS */
char	**argument_count(int argc, char **argv);

/* ROTATE */
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* SWAP */
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
/* REVERSE_ROTATE */
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* PUSH */
void	push(t_stack **s_give, t_stack **s_receive);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);

/* PUSH_SWAP */
int		is_sorted(t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size);

/* STACK RELATED */
void	append_node(t_stack **stack_a, int num);
void	fill_stack(t_stack **stack_a, char **input, int argc); /*int argc*/
void	send_to_b(t_stack **stack_a, t_stack **stack_b, int size);

/* STACK RELATED 2 */
void	init_index(t_stack *stack);
void	set_index(t_stack *stack);
void	set_position(t_stack *stack);
void	init_target_pos(t_stack *stack);

/* ERROR RELATED */
int		repeat_num(int num, t_stack **stack);
int		valid_argument(char *arg);
char	**arg_prep(int argc, char **argv);
void	error_manage(char **input, int type,
			t_stack **stack, int argc); /*t_stack **stack,*/

/* UTILS */
long	ft_atol(char *s);
t_stack	*get_last(t_stack *lst);
t_stack	*get_previous_last(t_stack *lst);
void	ft_lstaddback(t_stack **lst, t_stack *new);
int		ft_abs(int num);

/* UTILS 2 */
void	above_median(t_stack **stack);
void	is_big(t_stack **stack, int size);
int		med_position(t_stack *stack);
int		get_size(t_stack *lst);
int		max_value(int one, int two);

/* SORT */
void	sort_three(t_stack **stack);
void	sort_much(t_stack **stack_a, t_stack **stack_b, int size);
void	set_target_pos(t_stack **stack_a, t_stack **stack_b);
int		find_min_index(t_stack *stack);
void	calculate_costs(t_stack **stack_a, t_stack **stack_b);
void	calculate_individual_costs(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_cheapest(t_stack *stack);
void	execute_move(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min_node(t_stack *stack);

/* FREE */
void	free_input(char **input, int argc);
void	free_stack(t_stack *stack_a);

#endif