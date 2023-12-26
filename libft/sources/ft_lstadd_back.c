/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:59:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp_lst = ft_lstlast(*lst);
			temp_lst->next = new;
		}
	}
}

/*
static void	ft_lst_print(t_list *begin_list)
{
	t_list	*temp_lst;
	temp_lst = begin_list;
	
	while (temp_lst)
	{
		printf("%s\n", (char *)temp_lst->content);
		temp_lst = temp_lst->next;
	}
}

// Test when the list is not empty
// int	main(void)
// {
//     t_list  **list;
// 	t_list	*begin_list = ft_lstnew("Daniel");
//     list = &begin_list;
// 	begin_list->next = ft_lstnew("Alejandro");
// 	begin_list->next->next = ft_lstnew("Nieto");
// 	ft_lst_print(begin_list);
//     printf("\n\n\n");
//     t_list *new_node = ft_lstnew("Castro");
// 	ft_lstadd_back(list, new_node);
//     ft_lst_print(begin_list);
// }

// Test when the list is empty
// int	main(void)
// {
//     t_list  **list;
// 	t_list	*begin_list = NULL;
//     list = &begin_list;
//     t_list *new_node = ft_lstnew("Daniel");
// 	ft_lstadd_back(list, new_node);
//     ft_lst_print(begin_list);
// }
*/