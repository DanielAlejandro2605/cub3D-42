/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanda <amanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:39:55 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/04/25 20:14:08 by amanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;

	if (*lst)
	{
		while (*lst)
		{
			temp_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp_lst;
		}
		*lst = 0;
	}
}
