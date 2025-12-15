/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 12:18:00 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 13:38:45 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0] && i + little_len <= len)
		{
			if (!(ft_strncmp(&big[i], little, little_len)))
				return (&((char *)big)[i]);
		}
		i++;
	}
	return ((void *)0);
}

// int	main(void)
// {
// 	const char *big = "foo bar baz";
// 	const char *little = "baz";
// 	size_t i = 10;
// 	char *mein = ft_strnstr(big, little, i);
// 	char *org = strnstr(big, little, i);
// 	printf("Mein: %p\nOrg:  %p", mein, org);
// }
