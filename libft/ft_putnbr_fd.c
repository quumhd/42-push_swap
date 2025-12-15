/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:50:21 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/16 19:04:55 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		i++;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		length;
	char	char_num[12];

	length = ft_count_digits(n);
	char_num[length - 1] = '\0';
	if (n < 0)
		char_num[0] = '-';
	if (n == 0)
		char_num[0] = '0';
	while (n != 0)
	{
		if (n > 0)
			char_num[length - 2] = n % 10 + '0';
		else
			char_num[length - 2] = (n % 10 * -1) + '0';
		n = n / 10;
		length--;
	}
	ft_putstr_fd(char_num, fd);
}
