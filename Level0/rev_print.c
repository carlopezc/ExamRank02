/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:17 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/10 11:04:05 by carlopez         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	len;

	if (argc == 2 && argv[1])
	{
		len = ft_strlen(argv[1]) - 1;
		while (len >= 0)
			write(1, &argv[1][len--], 1);
	}
	write(1, "\n", 1);
	return (0);
}
