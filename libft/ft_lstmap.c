/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:39:02 by jdreissi          #+#    #+#             */
/*   Updated: 2025/10/19 14:11:39 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*start;
	void	*temp;

	if (!lst)
		return (NULL);
	start = 0;
	while (lst)
	{
		temp = f(lst->content);
		new_list = ft_lstnew(temp);
		if (!new_list)
		{
			del(temp);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_list);
		lst = lst->next;
	}
	return (start);
}
