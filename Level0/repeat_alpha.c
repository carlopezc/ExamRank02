/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:10:20 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/03 10:04:58 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	repeat;

	i = 0;
	j = 0;
	repeat = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				repeat = argv[1][i] - 64;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat = argv[1][i] - 96;
			else
				write(1, &argv[1][i], 1);
			if (repeat > 0)	
				while (j++ < repeat)
					write(1, &argv[1][i], 1);
			i++;
			j = 0;
			repeat = 0;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
