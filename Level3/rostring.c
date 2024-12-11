/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:26:41 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/11 21:24:44 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_skip_word(char *argv)
{
	int	i;
	//int	j;

	i = 0;
	while (argv[i] && ((argv[i] == 32) || (argv[i] >= 9 && argv[i] <= 13)))
		i++;
	//j = i;
	while (argv[i] && (!((argv[i] == 32) || (argv[i] >= 9 && argv[i] <= 13))))
		i++;
	//if (j == i)
		//return (0);
	return (i);
}

int	write_clean(char *argv, int i)
{
	int	flag;

	if (!argv)
		return (-1) ;
	flag = 0;
	while (argv[i] != '\0')
	{
		while (argv[i] && (!((argv[i] == 32) || (argv[i] >= 9 && argv[i] <= 13))))
		{
			write(1, &argv[i++], 1);
			flag = 1;
		}
		while (argv[i] && ((argv[i] == 32) || (argv[i] >= 9 && argv[i] <= 13)))
			i++;
		if (flag && argv[i] != '\0')
			write(1, " ", 1);
	}
	return (flag);
}

void	write_first(char *argv, int pos, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
		write(1, " ", 1);
	while (i < pos)
	{
		while (argv[i] && (!((argv[i] == 32) || (argv[i] >= 9 && argv[i] <= 13))))
			write(1, &argv[i++], 1);
		while (argv[i] && ((argv[i] == 32) || (argv[i] >= 9 && argv[i] <= 13)))
			i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	first_pos;
	int	i;

	if (argc > 1 && argv[1])
	{
		first_pos = ft_skip_word(argv[1]);
		//if (!first_pos)
			//return (write(1, "\n", 1), 0);
		if (write_clean(argv[1], first_pos) == 1)
			write_first(argv[1], first_pos, 1);
		else
			write_first(argv[1], first_pos, 0);

	}
	return (write(1, "\n", 1), 0);
}
