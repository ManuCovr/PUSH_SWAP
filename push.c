#include "push_swap.h"

static void		push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if(!*src)
		return ;
	push_node = *src;
	*src = (*src)->next; // move to the next node, which will become the new top node
	if (*src)
		(*src)->prev = NULL; // set current node as the head of the stack
	push_node->prev = NULL; // detach the node to push it from its stack
	if (!*dst) // check if stack (destiny) is empty
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}