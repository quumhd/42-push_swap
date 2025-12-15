/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:37:45 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 13:37:58 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dest;
	unsigned char	*t_src;

	if (!src && !dest)
		return (dest);
	i = 0;
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	while (i < n)
	{
		(t_dest)[i] = (t_src)[i];
		i++;
	}
	return (dest);
}
