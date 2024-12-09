/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:35:13 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 17:41:43 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (-1);
}
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (write(1, "\n", 1));
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((ft_isalpha(argv[i][j]) == 1) && argv[i][j + 1] && ((argv[i][j + 1]
				< 9 || argv[i][j + 1] > 13) && (argv[i][j + 1] != 32)))
				argv[i][j] = argv[i][j] + 32;
			else if ((ft_isalpha(argv[i][j]) == 0) && 
					((argv[i][j + 1] >= 9 && argv[i][j+ 1] <= 13) 
					 || (argv[i][j + 1] == 32 || argv[i][j + 1] == '\0')))
				argv[i][j] = argv[i][j] - 32;
			write(1, &argv[i][j++], 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
