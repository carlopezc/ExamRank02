/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:29:43 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/04 12:42:52 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_bits(unsigned char number);

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	right_half;
	unsigned char	left_half;
	unsigned char	swap;

	right_half = (octet >> 4);
	left_half = (octet << 4);
	swap = (left_half | right_half);
	return (swap);
}

#include <stdio.h>

int	main(void)
{
	print_bits(100);
	write(1, "\n", 1);
	print_bits(swap_bits(100));
	return (0);
}
