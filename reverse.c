#include "push_swap.h"

static void		rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	putstr("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	putstr("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	putstr("rrr\n");
}
