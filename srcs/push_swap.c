/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:46:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/30 16:44:29 by youngcho         ###   ########.fr       */
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
	printf("###init###\n");
	printf("top:%p\n", a->top);
	while (node)
	{
		printf("	%d\n", node->data);
		printf("	next:%p | curr:%p | prev:%p\n", node->next, node, node->prev);
		node = node->prev;
	}
	printf("bottom:%p\n", a->bottom);
	printf("\n");
	
	// 스택에 요소가 없을 때 pop을 하면 segmentation fault
	// pa pb 할 때 예외처리 해줘야 함
	pop(a);
	pop(a);
	node = a->top;
	printf("###pop 2###\n");
	printf("top:%p\n", a->top);
	while (node)
	{
		printf("	%d\n", node->data);
		printf("	next:%p | curr:%p | prev:%p\n", node->next, node, node->prev);
		node = node->prev;
	}
	printf("bottom:%p\n", a->bottom);
	printf("\n");

	push(a, 6);
	printf("###push 1###\n");
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
	
	rotate(a);
	node = a->top;
	printf("###rotate 1###\n");
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
	printf("###reverse rotate 3###\n");
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
	node = a->top;
	printf("###swap 2###\n");
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
