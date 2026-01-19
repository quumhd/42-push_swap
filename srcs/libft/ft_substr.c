/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:16:24 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 11:16:24 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_return_null(void)
{
	char	*substring;

	substring = (char *)malloc(1);
	if (!substring)
		return ((void *)0);
	substring[0] = 0;
	return (substring);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*substring;

	i = 0;
	length = ft_strlen(s);
	if (start >= length)
		return (ft_return_null());
	if (start + len <= length)
		substring = (char *)malloc((len + 1) * sizeof(char));
	else
		substring = (char *)malloc((length - start + 1) * sizeof(char));
	if (!substring)
		return ((void *)0);
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = 0;
	return (substring);
}

// int	main(void)
// {
// 	const char *s = "hallo ab hier!";
// 	unsigned int i = 7;
// 	size_t j = 11;
// 	char *res = ft_substr(s, i, j);
// 	printf("%s", res);
// }