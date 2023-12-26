/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:37:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (!lst)
			*lst = new;
		new->next = *lst;
		*lst = new;
	}
}

/*static void	ft_lst_print(t_list *begin_list)
{
	t_list	*temp_lst;
	temp_lst = begin_list;
	
	while (temp_lst)
	{
		printf("%s\n", (char *)temp_lst->content);
		temp_lst = temp_lst->next;
	}
}

int	main(void)
{
    t_list  **list;
	t_list	*begin_list = ft_lstnew("Alejandro");
    list = &begin_list;
	begin_list->next = ft_lstnew("Nieto");
	begin_list->next->next = ft_lstnew("Castro");
	ft_lst_print(begin_list);
    printf("\n\n\n");
    t_list *new_node = ft_lstnew("Daniel");
    ft_lstadd_front(list, new_node);
    ft_lst_print(begin_list);
}*/