/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:49:52 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/04 13:31:18 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet);

/*unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	first_quart;
	unsigned char	second_quart;
	unsigned char	third_quart;
	unsigned char	forth_quart;

	first_quart = (octet << 4);
	second_quart = first_quart;
	first_quart = (octet << 2);
	second_quart = (octet >> 2);
	third_quart = (octet >> 4);
	forth_quart = third_quart;
	third_quart = (octet << 2);
	forth_quart = (octet >> 2);
	return (first_quart | second_quart | third_quart | forth_quart);
}*/

unsigned char	reverse_bits(unsigned char number)
{
	unsigned char bit[8];
	int	i;

	i = 0x0;
	while (i < 8)
	{
		bit[i] = (number >> i & 0x1) + '0';
		i++;
	}
	return (bit[0] | bit[1] | bit[2] | bit[3] | bit[4] | bit[5] | bit[6] | bit[7]);
}

int	main(void)
{
	print_bits(100);
	write(1, "\n", 1);
	print_bits(reverse_bits(100));
	return (0);
}
