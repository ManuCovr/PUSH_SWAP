#include "push_swap.h"

static void		rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void		rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void		move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above && cheapest_node->target_node->above)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above) && !(cheapest_node->target_node->above))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a'); // make sure the cheapest node is at the top
	prep_for_push(b, cheapest_node->target_node, 'b'); // make sure target node is at the top
	pb(b, a);
}

static void		move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a'); // make sure 'b's target 'a' is on top
	pa(a, b);
}

static void		min_to_top(t_stack_node **a) // moves the smallest to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) // while smallest number is not on top
	{
		if (find_min(*a)->above)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a)) // if stack A has more than 3 nodes and arent sorted
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a)) // after pushing, check if there are STILL 3 nodes
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}