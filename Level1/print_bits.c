/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:16:14 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/04 12:43:12 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char number)
{
	int	i;
	char	bit;

	i = 8;
	while (i-- > 0)
	{
		bit = (number >> i & 1) + '0';
		write(1, &bit, 1);
	}
	return ;
}
