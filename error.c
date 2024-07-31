/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:49:31 by mde-maga          #+#    #+#             */
/*   Updated: 2024/07/31 11:32:36 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if ((str_n[i] == '+' && str_n[i + 1] == '0')
		|| (str_n[i] == '-' && str_n[i + 1] == '0'))
		return (1);
	if (*str_n == '+' || *str_n == '-')
		i++;
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_dup(t_stack_node *a, int n) // checks for duplicate inputs
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
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
	putstr_fd("Error\n", 2);
	exit(1);
}
