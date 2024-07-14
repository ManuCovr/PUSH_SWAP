#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack) // check for empty stack
		return ;
	median = stack_len(stack) / 2; // calculate median
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above = true;
		else
			stack->above = false;
		stack = stack->next;
		++i;
	}
}

static void set_target_a (t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match; // the best match index stores the value of the closest small nbr so far

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN) // if LONG_MIN hasnt changed, then theres no smaller nbr
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void		analysis_a(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above)) // check for errors in the median calculations
			a->push_cost = len_a - (a->index); 
		if (a->target_node->above)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}

}
void set_cheapest(t_stack_node *stack)
{
	long			cheapest_v;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_v = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_v)
		{
			cheapest_v = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	analysis_a(a, b);
	set_cheapest(a);
}