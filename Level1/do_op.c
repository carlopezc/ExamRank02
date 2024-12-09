/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:59:52 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 16:31:53 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
*/
int	main(int argc, char **argv)
{
	int	num1;
	int	num2;

	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		if (argv[2][0] == '*')
			printf("%i\n", (num1 * num2));
		else if (argv[2][0] == '/')
			printf("%i\n", (num1 / num2));
		else if (argv[2][0] == '+')
			printf("%i\n", (num1 + num2));
		else if (argv[2][0] == '-')
			printf("%i\n", (num1 - num2));
		else if (argv[2][0] == '%')
			printf("%i\n", (num1 % num2));
	}
	else
		write(1, "\n", 1);	
	return (0);
}
