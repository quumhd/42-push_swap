/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:44:38 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/19 14:23:09 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_c;

	c_c = (char) c;
	i = ft_strlen(s) + 1;
	while (--i >= 0)
		if (s[i] == c_c)
			return (&((char *)s)[i]);
	return ((void *)0);
}

// int	main(void)
// {
// 	char c = 0;
// 	const char *test = "teste";
// 	char *mein = ft_strrchr(test, c);
// 	char *org = strrchr(test, c);
// 	printf("Mein: %p\nOrg:  %p\n", mein, org);
// }