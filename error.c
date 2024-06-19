#include "push_swap.h"

int		error_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if (!(*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);

}

int		error_dup(t_stack_node *a, int n) // checks for duplicate inputs
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
	}
	return (0);
}

void	free_my_mans(t_stack_node **stack) // frees stacks in case of error
{
	t_stack_node	*tmp;
	t_stack_node	*curr;
	
	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		curr->nbr = 0;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}


void	free_errors(t_stack_node **a)
{
	free_my_mans(a);
	ft_printf("Error\n");
	exit(1);
}