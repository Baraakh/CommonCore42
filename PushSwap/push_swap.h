# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		add_back(t_stack **a, int value);
int		stack_size(t_stack *a);
void	free_stack(t_stack **a);

void	put_error(void);
int		has_duplicate(t_stack *a, int value);
int		is_sorted(t_stack *a);
void	set_indexes(t_stack *a);

int		min_pos(t_stack *a);
int		max_pos(t_stack *a);

int		parse_args(int ac, char **av, t_stack **a);

void	op_sa(t_stack **a);
void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);

void	op_ra(t_stack **a);
void	op_rb(t_stack **b);

void	op_rra(t_stack **a);
void	op_rrb(t_stack **b);

void	sort_small(t_stack **a, t_stack **b, int size);
void	sort_chunk(t_stack **a, t_stack **b, int size);

# endif
