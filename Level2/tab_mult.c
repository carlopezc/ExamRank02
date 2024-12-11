/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:48 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/10 17:22:00 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi_positive(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] != '\0')
		number = number * 10 + (str[i++] - '0');
	return (number);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		write(1, &str[i++], 1);
	return ;
}

void	ft_putstr_nbr(int number)
{
	char	num;

	if (number > 9)
		ft_putstr_nbr(number / 10);
	num = (number % 10) + '0';
	write(1, &num, 1);
	return ;
}

int	main(int argc, char **argv)
{
	int	i;
	int	number;
	char	char_i;

	if (argc == 2)
	{
		i = 1;
		while (i <= 9 )
		{
			char_i = i + '0';
			write(1, &char_i, 1);
			write(1, " x ", 3);
			ft_putstr(argv[1]);
			write(1, " = ", 3);
			number = ft_atoi_positive(argv[1]) * i;
			ft_putstr_nbr(number);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
