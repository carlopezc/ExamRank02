/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:11:27 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/11 17:16:40 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"


/*
int	ascending(int a, int b)
{
	return (a <= b);
}
*/

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	struct s_list	*first;
	struct s_list	*second;
	struct s_list	*prev;

	if (!lst || !(lst->next))
		return (NULL);
	first = lst;
	second = lst->next;
	prev = NULL;
	while (first && second)
	{
		if (!(*cmp)(first->data, second->data))
		{
			first->next = second->next;
			second->next = first;
			if (first == lst)
				lst = second;
			if (prev)
				prev->next = second;
			first = lst;
			second = lst->next;
			prev = NULL;
		}
		else
		{
			prev = first;
			first = first->next;
			second = second->next;
		}
	}
	return (lst);
}
/*
int	main(void)
{
	struct s_list	*nodo1;
	struct s_list	*nodo2;
	struct s_list	*nodo3;
	struct s_list	*temp;
	
	nodo1 = (struct s_list *)malloc(1 * sizeof(struct s_list));
	if (!nodo1)
		return (0);
	nodo1->data = 3;
       	nodo2 = (struct s_list *)malloc(1 * sizeof(struct s_list));
	if (!nodo2)	
		return (0);
	nodo2->data = 1;
	nodo3 = (struct s_list *)malloc(1 * sizeof(struct s_list));
	if (!nodo3)
		return (0);
	nodo3->data = 2;
	nodo1->next = nodo2;
	nodo2->next = nodo3;
	nodo3->next = NULL;
	temp = nodo1;
	printf("ANTES DE ORDENAR : \n");
	while (temp->next)
	{
		printf("%i", temp->data);
		temp = temp->next;
	}
	printf("%i\n", temp->data);
	printf("DESPUES DE ORDENAR: \n");
	temp = sort_list(nodo1, ascending);
	while (temp->next)
	{
		printf("%i", temp->data);
		temp = temp->next;
	}
	printf("%i\n", temp->data);
	return (0);
}
*/
