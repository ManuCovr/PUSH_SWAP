#include "push_swap.h"

int	stack_len(t_stack_node *stack) // check the stack lenght
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next) // loop until the end of the stack
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack) // check if stack is sorted
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr) // check if the current value is larger than the next node's value
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack) // finds lowest nbr
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min) // check if current node is smaller than the smallest so far
		{
			min = stack->nbr; // if yes, update
			min_node = stack; // point to the node with the smallest number
		}
		stack = stack->next; // move to the next node
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack) // self-explanatory lol
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next; // move to the next node
	}
	return (max_node);
}