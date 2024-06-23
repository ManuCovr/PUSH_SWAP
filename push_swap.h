#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
    int                 nbr;
    int                 index;
    int                 push_cost;
    bool                above;
    bool                cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;

// Errors

int		error_syntax(char *str_n);
int		error_dup(t_stack_node *a, int n);
void	free_my_mans(t_stack_node **stack);
void	free_errors(t_stack_node **a);

//stacks

void	init_stack_a(t_stack_node **a, char **argv);
char	**split(char *s, char c);
int	stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	sort_three(t_stack_node **a);

//Commands
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);

//Nodes

t_stack_node	*get_cheapest(t_stack_node *stack);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void set_cheapest(t_stack_node *stack);
void	current_index(t_stack_node *stack);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	prep_for_push(t_stack_node **stack, t_stack_node *top, char stack_name);

#endif