/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:35:37 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 13:37:49 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	ptr = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return ((void *)0);
}

// int	main(void)
// {
// 	char *test = "wgb3084yut93wt4ri87uh";
// 	int find = 'h';
// 	size_t i = 1022;
// 	void *mein = ft_memchr((const void *)test, find, i);
// 	void *org = memchr((const void *)test, find, i);
// 	printf("Mein: %p\nOrg:  %p\n", mein, org);
// }