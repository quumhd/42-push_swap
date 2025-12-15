/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:25:40 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/14 16:35:49 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
}

// int main(void)
// {
// 	put_fstr("test");
// }
