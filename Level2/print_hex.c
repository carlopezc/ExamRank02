/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:42:05 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 14:05:15 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	num = 0;
	if (str[i] == '-')
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10  + (str[i] - '0');
		i++;
	}
	return (num);
}

void	ft_print_hex(int num)
{
	char	n;

	if (num > 15)
		ft_print_hex(num / 16);
	if (num % 16 >= 10 && num % 16 <= 15)
		n = (num % 16) - 10 + 'a';
	else if (num % 16 <= 9)
		n = (num % 16) + '0';
	write(1, &n, 1);
}

int	main(int argc, char **argv)
{
	int	num;
	char	n;
	
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		if (num >= 0)
			ft_print_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}
