/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:00:11 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
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
// 	ft_lstadd_back(list, ft_lstnew("Alejandro"));
// 	ft_lstadd_front(list, ft_lstnew("Nieto"));
// 	ft_lstadd_back(list, ft_lstnew("Ecole"));
// 	ft_lstadd_front(list, ft_lstnew("42"));
// 	ft_lstadd_back(list, ft_lstnew("Paris"));
// 	ft_lstadd_front(list, ft_lstnew("Barcelona"));
// 	ft_lstadd_back(list, ft_lstnew("Istambul"));
// 	ft_lstadd_front(list, ft_lstnew("Bogota"));
// 	ft_lst_print(begin_list);
//     printf("\n\n\n");
// 	printf("Size of list : %d\n", ft_lstsize(begin_list));
// }

// Test when the list is empty
// int	main(void)
// {
//     t_list  **list;
// 	t_list	*begin_list = NULL;
//     list = &begin_list;
// 	printf("Size of list : %d\n", ft_lstsize(begin_list));
// }
*/