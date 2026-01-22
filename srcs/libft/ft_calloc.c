/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:12:20 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/22 11:37:58 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	memblock;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return ((void *)0);
	memblock = nmemb * size;
	allocated = malloc (memblock);
	if (!allocated)
		return ((void *)0);
	ft_bzero(allocated, memblock);
	return (allocated);
}
