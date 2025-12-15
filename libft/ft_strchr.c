/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:22:58 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 19:19:27 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_c;

	i = -1;
	c_c = (char)c;
	if (c_c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (s[++i])
		if (s[i] == c_c)
			return (&((char *)s)[i]);
	return ((void *)0);
}

// int	main(void)
// {
// 	const char *test = "iwgpqinnjsVBoibwrn";
// 	char *mein = ft_strchr(test, '\0');
// 	char *org = strchr(test, '\0');
// 	printf("Mein: %p\nOrg:  %p\n", mein, org);
// }