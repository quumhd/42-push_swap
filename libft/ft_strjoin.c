/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:16:48 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 11:16:48 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*joined;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(len * sizeof(char));
	if (!joined)
		return ((void *)0);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[len - 1] = 0;
	return (joined);
}

// int	main(void)
// {
// 	char *s1 = "hallo1";
// 	char *s2 = "hallo2";
// 	char *s3 = ft_strjoin(s1, s2);
// 	printf("%s", s3);
// }