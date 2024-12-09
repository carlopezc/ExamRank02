/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:26:56 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 20:51:11 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_in_str(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i <= pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		if (argv[1])
		{
			write(1, &argv[1][i++], 1);
			while (argv[1][i] != '\0')
			{
				if (is_in_str(argv[1], argv[1][i], i - 1) == 0)
					write(1, &argv[1][i++], 1);
				else
					i++;
			}
		}
		j = 0;
		if (argv[2])
		{
			while (argv[2][j] != '\0')
			{
				if ((is_in_str(argv[1], argv[2][j], (i - 1)) == 0) && (is_in_str(argv[2], argv[2][j], j - 1) == 0))
					write(1, &argv[2][j++], 1);
				else
					j++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
