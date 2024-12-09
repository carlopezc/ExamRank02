/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:53:49 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/03 17:11:03 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*number;
	char	num_char;
	int	nbr_len;
	int	nbr_cpy;
	int	negative;

	nbr_len = 0;
	if (nbr == -2147483648)
	{
		number = (char *)malloc(12);
		if (!number)
			return (NULL);
		number[11] = '\0';
		number = "-2147483648";
		return (number);
	}
	negative = 0;
	if (nbr < 0)
	{
		negative = 1;
		nbr_len++;
		nbr = nbr * -1;
	}
	nbr_cpy = nbr;
	while (nbr_cpy > 9)
	{
		nbr_cpy = nbr_cpy / 10;
		nbr_len++;
	}
	nbr_len++;
	number = (char *)malloc((nbr_len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[nbr_len--] = '\0';
	while (nbr > 9)
	{
		num_char = (nbr % 10) + '0';
		number[nbr_len--] = num_char;
		nbr = nbr / 10;
	}
	num_char = (nbr % 10) + '0';
	number[nbr_len--] = num_char;
	if (negative == 1)
		number[nbr_len] = '-';
	return (number);
}
