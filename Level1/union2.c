/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:33 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/03 15:57:01 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	search(char	*str, char c, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (str[j++] == c)
			return (1); 
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 3)
	{
		write(1, &argv[1][i++], 1);
		while (argv[1][i] != '\0')
		{
			if (!search(argv[1], argv[1][i], i) && argv[1][i] != '"')
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j] != '\0')
		{
			if ((!search(argv[2], argv[2][j], j)) && argv[2][j] != '"' && (!search(argv[1], argv[2][j], i)))
				write(1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
