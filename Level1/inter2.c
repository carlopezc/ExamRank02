/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:29:22 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/10 12:37:29 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_search(char *str, char c, int pos)
{
	int	i;

	i = 0;
	if (pos == -1)
	{
		while (str && str[i] != '\0')
		{
			if (str[i++] == c)
				return (1);
		}
	}
	else
	{
		while (i < pos)
		{
			if (str[i++] == c)
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3 && argv[1] && argv[2])
	{
		i = 0;
		if (ft_search(argv[2], argv[1][i], -1))
			write(1, &argv[1][i++], 1);
		while (argv[1][i] != '\0')
		{
			if (!ft_search(argv[1], argv[1][i], i) && ft_search(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
