/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:25:40 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/23 14:47:36 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
	exit (1);
}

void	put_str(char *s)
{
	write(STDOUT_FILENO, s, ft_strlen(s));
}
