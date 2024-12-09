/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:44:48 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/09 18:01:28 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(int num)
{
	int	len;

	len = 0;
	while (num > 9)
	{
		len++;
		num = num / 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*num;
	int	len;
	int	negative;

	if (nbr == -2147483648)
	{
		num = (char *)malloc(12);
		if (!num)
			return (NULL);
		num = "-2147483648";
		num[12] = '\0';
		return (num);
	}
	len = 0;
	negative = 0;
	if (nbr < 0)
	{
		len++;
		negative = -1;
		nbr = -1 * nbr;
	}
	len = len + ft_strlen(nbr);
	num = (char *)malloc(len + 1);
	if (!num)
		return (NULL);
	num[len--] = '\0';
	while (nbr > 9 && len >= 0)
	{
		num[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	num[len] = (nbr % 10) + '0';
	if (negative == -1)
		num[--len] = '-';
       return (num);
}
