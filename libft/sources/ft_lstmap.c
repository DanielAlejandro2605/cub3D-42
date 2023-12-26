/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:17:25 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux_list;
	t_list	*temp_lst;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	aux_list = new_list;
	lst = lst->next;
	while (lst)
	{
		temp_lst = ft_lstnew((*f)(lst->content));
		if (!temp_lst)
			ft_lstdelone(temp_lst, del);
		aux_list->next = temp_lst;
		aux_list = temp_lst;
		lst = lst->next;
	}
	return (new_list);
}

/*static void	*ft_aux(void *p)
{
	char	*cpy;
	char	*res;
	
	cpy = (char *)p;
	res = (void *)ft_strdup(cpy);
	return (res);
}

static void	ft_free_node(void *p)
{
	free(p);	
}

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

int	main(void)
{
	t_list  **list;
	t_list	*begin_list = ft_lstnew("Daniel");
    list = &begin_list;
	ft_lstadd_back(list, ft_lstnew("Alejandro"));
	ft_lstadd_front(list, ft_lstnew("Nieto"));
	ft_lstadd_back(list, ft_lstnew("Ecole"));
	ft_lstadd_front(list, ft_lstnew("42"));
	t_list	*element = ft_lstnew("Paris");
	ft_lstadd_back(list, element);
	ft_lstadd_front(list, ft_lstnew("Barcelona"));
	ft_lstadd_back(list, ft_lstnew("Istambul"));
	ft_lstadd_front(list, ft_lstnew("Bogota"));
	ft_lst_print(begin_list);
    printf("\n\n\n");
	printf("Size of list : %d\n", ft_lstsize(begin_list));
	t_list *lst_map = ft_lstmap(begin_list, &ft_aux, &ft_free_node);
	printf("New list:\n");
	ft_lst_print(lst_map);
}*/