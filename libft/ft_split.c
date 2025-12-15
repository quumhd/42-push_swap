/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:16:52 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/18 15:16:33 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	length;
// 	char	*substring;

// 	i = 0;
// 	length = ft_strlen(s);
// 	if (start >= length)
// 	{
// 		substring = (char *)malloc(1);
// 		substring[0] = 0;
// 		return (substring);
// 	}
// 	if (start + len <= length)
// 		substring = (char *)malloc((len + 1) * sizeof(char));
// 	else
// 		substring = (char *)malloc((length - start + 1) * sizeof(char));
// 	if (!substring)
// 		return ((void *)0);
// 	while (i < len && s[start + i])
// 	{
// 		substring[i] = s[start + i];
// 		i++;
// 	}
// 	substring[i] = 0;
// 	return (substring);
// }

static int	ft_word_counter(char const *s, char c, int len)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	while (i <= len && s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		words++;
	}
	return (words);
}

static int	ft_strnlen(char const *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start] != c && s[start])
	{
		start ++;
		i++;
	}
	return (i);
}

int	ft_s_count(char const *s, char c, int outer_index)
{
	int	i;
	int	c_counter;

	i = 0;
	c_counter = 0;
	while (s[i] == c)
		i++;
	while (s[i] && c_counter < outer_index)
	{
		while (s[i] != c)
			i++;
		while (s[i] == c)
			i++;
		c_counter++;
	}
	return (i);
}

static char	**ft_free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ((void *)0);
}

char	**ft_split(char const *s, char c)
{
	int		outer_index;
	int		next_len;
	int		s_index;
	int		words;
	char	**split;

	outer_index = 0;
	s_index = 0;
	words = ft_word_counter(s, c, ft_strlen(s));
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return ((void *)0);
	while (outer_index < words)
	{
		s_index = ft_s_count(s, c, outer_index);
		next_len = ft_strnlen(s, s_index, c);
		split[outer_index] = ft_substr(s, s_index, next_len);
		if (!split[outer_index])
			return (ft_free_all(split));
		outer_index++;
	}
	split[words] = ((void *)0);
	return (split);
}

// int main(void)
// {
// 	int i = -1;
// 	const char *s = "hallo";
// 	char **split = ft_split(s, ' ');
// 	while(split[++i])	
// 		printf("%s\n", split[i]);
// }
