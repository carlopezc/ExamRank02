/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:00:40 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 19:32:01 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1] && argv[1][i])
		{
			while ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') && argv[1][i])
			{
				write(1, "_", 1);
				argv[1][i] = argv[1][i] + 32;
				write(1, &argv[1][i++], 1);
			}
			while((argv[1][i] < 'A' || argv[1][i] > 'Z') && argv[1][i])
				write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1 );
	return (0);
}
