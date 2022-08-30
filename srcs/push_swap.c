/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 16:19:11 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_argv	argv_int;
	t_stack	*a;
	t_stack	*b;

// 이미 정렬된 arguments 미리 처리
	parsing_argument(&argv_int, argc, argv);
	init_stack_a_and_b(&a, &b, &argv_int);
	t_node *node = a->top;
	printf("top:%p\n", a->top);
	while (node)
	{
		printf("	%d\n", node->data);
		printf("	next:%p | curr:%p | prev:%p\n", node->next, node, node->prev);
		node = node->prev;
	}
	printf("bottom:%p\n", a->bottom);
	printf("\n");
	
	rotate(a);
	rotate(a);
	rotate(a);
	node = a->top;
	printf("top:%p\n", a->top);
	while (node)
	{
		printf("	%d\n", node->data);
		printf("	next:%p | curr:%p | prev:%p\n", node->next, node, node->prev);
		node = node->prev;
	}
	printf("bottom:%p\n", a->bottom);
	printf("\n");

	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	node = a->top;
	printf("top:%p\n", a->top);
	while (node)
	{
		printf("	%d\n", node->data);
		printf("	next:%p | curr:%p | prev:%p\n", node->next, node, node->prev);
		node = node->prev;
	}
	printf("bottom:%p\n", a->bottom);
	printf("\n");

	swap(a);
	swap(a);
	node = a->top;
	printf("top:%p\n", a->top);
	while (node)
	{
		printf("	%d\n", node->data);
		printf("	next:%p | curr:%p | prev:%p\n", node->next, node, node->prev);
		node = node->prev;
	}
	printf("bottom:%p\n", a->bottom);
	printf("\n");
	return (0);
}
