/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:42:01 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/14 17:27:05 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	integer_limit(char *s)
{
	
} 

int	is_argv_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc <= 1)
		return (0);
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
		if (j > 11)
			return (0);
		else if (j == 10 || j == 11)
			if (!integer_limit)
				return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (is_argv_valid(argc, argv) == 0)
		return (put_error("Error"), 0);
	else 
		put_error("test");
}
