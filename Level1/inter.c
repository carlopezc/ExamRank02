/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:06:58 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/10 11:28:17 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_search(char *str, char c, int pos)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	if (pos == -1)
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (1);
			i++;
		}
	}
	else
	{
		while (i < pos)
		{
			if (str[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	flag;

	if (argc == 3 && argv[1] && argv[2])
	{
		i = 0;
		flag = 0;
		while (argv[1][i] != '\0')
		{
			if ((ft_search(argv[2], argv[1][i], -1) == 1) && !flag)
			{
				flag = 1;
				write(1, &argv[1][i++], 1);
			}
			if (ft_search(argv[1], argv[1][i], i) == 0 && (ft_search(argv[2], argv[1][i], -1) == 1))
					write(1, &argv[1][i++], 1);
			else
				i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
