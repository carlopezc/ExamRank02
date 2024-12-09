/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:40 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/03 15:34:55 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnumber(int number)
{
	char	num;

	if (number > 9)
		ft_putnumber(number / 10);
	num = (number % 10) + '0';
	write(1, &num, 1);
}

int	main(void)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnumber(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
