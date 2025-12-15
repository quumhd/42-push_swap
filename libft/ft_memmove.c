/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:50:18 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 13:38:01 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)dest)[n - 1] = ((unsigned char *) src)[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else if (dest > src)
		return (ft_memrcpy(dest, src, n));
	else
		return (dest);
}
