#include "push_swap.h"

static void		rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack; // setting the current TOP node as the last node 
	*stack = (*stack)->next; // assign the top node the node after it 
	(*stack)->prev = NULL; // detach the current TOP node from the previous
	last_node->next->prev = last_node; // reconnect
	last_node->next->next = NULL; // terminate null stack
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}