/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:18:32 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/10 10:53:49 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (-1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1] && argv[1][i] != '\0')
		{
			if ((ft_isalpha(argv[1][i]) == 0) && argv[1][i] <= 'm')
				argv[1][i] = 122 - (argv[1][i] - 'a');
			else if ((ft_isalpha(argv[1][i]) == 0) && argv[1][i] >= 'n')
				argv[1][i] = 122 - (argv[1][i] - 'a');
			else if ((ft_isalpha(argv[1][i]) == 1) && argv[1][i] <= 'M')
				argv[1][i] = 90 - (argv[1][i] - 'A');
			else if ((ft_isalpha(argv[1][i]) == 1) && argv[1][i] >= 'N')
				argv[1][i] = 90 - (argv[1][i] - 'A');
			write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
