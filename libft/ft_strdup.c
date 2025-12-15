/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:04:47 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 13:38:19 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*duplicated;

	length = ft_strlen(s) + 1;
	duplicated = (char *)malloc((length) * sizeof(char));
	if (!duplicated)
		return ((void *)0);
	ft_strlcpy(duplicated, s, length);
	return (duplicated);
}
