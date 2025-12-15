/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:57:31 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/15 16:13:58 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fits_in_int(char *s, int j)
{
	if (j > 11)
		return (0);
	if (j == 10 && (ft_strncmp(s, "2147483647", 10) > 0))
		return (0);
	if (j == 11 && s[0] == '+')
		if (ft_strncmp(s, "+2147483647", 11) > 0)
			return (0);
	if (j == 11 && s[0] == '-')
		if (ft_strncmp(s, "-2147483648", 11) > 0)
			return (0);
	return (1);
}

int	is_argv_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc <= 1)
		exit (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (!fits_in_int(argv[i], j))
			return (0);
		j = 0;
		i++;
	}
	return (1);
}
