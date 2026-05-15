# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*new_stack(void);
void	push_node(t_stack *s, int val);
int		pop_node(t_stack *s);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *s);

char	**split_str(char *s);
void	free_split(char **arr);

t_stack	*parse_args(char **argv);

void	do_swap(t_stack *s);
void	do_rotate(t_stack *s);
void	do_rev_rotate(t_stack *s);

void	op_sa(t_stack *a);
void	op_ra(t_stack *a);
void	op_rra(t_stack *a);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);

void	op_sb(t_stack *b);
void	op_rb(t_stack *b);
void	op_rrb(t_stack *b);

void	op_ss(t_stack *a, t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

void	radix_sort(t_stack *a, t_stack *b);

# endif
