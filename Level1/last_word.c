/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:36 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/10 16:34:36 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(int start, int end, char *str)
{
	if (!str)
		return ;
	while (start <= end)
		write(1, &str[start++], 1);
	return ;
}

int	main(int argc, char **argv)
{
	int	len;
	int	end;
	int	start;

	if (argc == 2 && argv[1])
	{
		len = ft_strlen(argv[1]) - 1;
		if (len > 0)
		{
			while (((argv[1][len] >= 9 && argv[1][len] <= 13) || (argv[1][len] == 32)) && len > 0)
				len--;
			end = len;
			if (end != 0)
			{
				while (((argv[1][len] < 9 || argv[1][len] > 13) && (argv[1][len] != 32)) && len > 0)
					len--;
				start = len + 1;
				ft_putstr(start, end, argv[1]);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
