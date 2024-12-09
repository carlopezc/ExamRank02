/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:02:59 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/03 16:49:44 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_search_char(char *str, char c, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_search_str(char *str, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str2[i] != '\0')
	{
		while ((str[j] == str2[i] || !ft_search_char(str, str2[i], j + 1)) && str[j])
		{
			i++;
			j++;
		}
		if (str[j] == '\0')
			return (1);
		if (ft_search_char(str, str2[i], j + 1))
			return (0);
		j = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_search_str(argv[1], argv[2]))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
