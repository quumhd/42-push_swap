/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:24:13 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/14 16:57:52 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size == 0)
		return (ft_strlen(src));
	while (++i < size - 1 && src[i])
		dest[i] = ((char *)src)[i];
	dest[i] = 0;
	return (ft_strlen(src));
}

// int	main(void)
// {
	// const char	*src = "hallotest";
	// char 		*dest;
	// dest = (char *)malloc(10);
	// ft_strlcpy(dest, src, 0);
	// printf("%s\n%s", src, dest);
// }
