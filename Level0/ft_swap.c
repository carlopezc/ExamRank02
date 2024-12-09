/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:39:31 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 19:59:41 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 5;
	printf("Valor de A inicial: %i\n", a);
	printf("Valor de B inicial: %i\n", b);
	printf("HACEMOS EL SWAP\n");
	ft_swap(&a, &b);
	printf("Valor de A final: %i\n", a);
	printf("Valor de B final: %i\n", b);
}
