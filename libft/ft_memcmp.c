/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:26:39 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 13:37:56 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	diff;

	diff = ft_cmp((unsigned char *)s1, (unsigned char *)s2, n);
	return (diff);
}

// int	main(void)
// {
// 	 char *s1 = "hallotest";
// 	const char *s2 = "€";
// 	size_t i = 11;
// 	int mein = ft_memcmp((const void *)s1, (const void *)s2, i);
// 	int org = memcmp((const void *)s1, (const void *)s2, i);
// 	printf("Mein: %d\nOrg:  %d\n", mein, org);
// }