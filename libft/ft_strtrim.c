/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:15:33 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/17 11:15:33 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft__empty_string(void)
{
	char	*trimmed_string;

	trimmed_string = (char *)malloc(1);
	if (!trimmed_string)
		return ((void *)0);
	trimmed_string[0] = 0;
	return (trimmed_string);
}

static int	ft_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		length;
	int		to_trim;
	char	*trimmed_string;

	i = 0;
	start = -1;
	to_trim = 0;
	length = ft_strlen(s1);
	if (!s1 || !set)
		return ((void *)0);
	while (ft_in_set(s1[++start], set) && s1[start])
		to_trim++;
	if (start == length)
		return (ft__empty_string());
	i = length;
	while (ft_in_set(s1[--i], set) && s1[i])
		to_trim++;
	trimmed_string = (char *)malloc((length - to_trim + 1) * sizeof(char));
	if (!trimmed_string)
		return ((void *)0);
	ft_strlcpy(trimmed_string, &s1[start], length - to_trim + 1);
	return (trimmed_string);
}

// int	main(void)
// {
// 	const char *s1 = "";
// 	const char *set = "";
// 	char *trimmed = ft_strtrim(s1, set);
// 	printf("%s", trimmed);
// }