/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:34:11 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 19:28:14 by jdreissi         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int		length;
	char	*char_num;

	length = ft_count_digits(n);
	char_num = (char *)malloc(length * sizeof(char));
	if (!char_num)
		return ((void *)0);
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
	return (char_num);
}

// int	main(void)
// {
// 	char *erg = ft_itoa(-2147483648);
// 	printf("%s", erg);
// }