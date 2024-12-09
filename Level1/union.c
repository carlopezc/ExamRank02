/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:03:16 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/03 13:02:45 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	found(char *str, char s, int i)
{
	int	j;

	if (!str)
		return (-1);
	j = 0;
	while (j < i)
	{
		if (str[j++] == s)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	len_argv1;

	i = 0;
	if (argc == 3)
	{
		write(1, &argv[1][i++], 1);
		while (argv[1][i] != '\0')
		{
			if (!found(argv[1], argv[1][i], i) && argv[1][i] != '"')
				write(1, &argv[1][i], 1);
			i++;
		}
		len_argv1 = i;
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (!found(argv[2], argv[2][i], i) && argv[2][i] != '"' && !found(argv[1], argv[2][i], len_argv1))
				write(1, &argv[2][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
