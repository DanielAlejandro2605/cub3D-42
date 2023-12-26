#include "../../includes/cub3D_struct.h"

t_list	*generic_get_node_by_idx(t_list **lst, int idx)
{
	t_list	*lst_ptr;
	int		i;

	if (lst)
	{
		lst_ptr = *lst;
		i = 0;
		while (i < idx)
		{
			i++;
			lst_ptr = lst_ptr->next;
		}
		return (lst_ptr);
	}
	return (NULL);
}

static t_list	*generic_lst_malloc_node(size_t data_size)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc(data_size);
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

int	generic_lst_add_node(t_list **lst, void *data, size_t data_size)
{
	t_list			*new_node;

	new_node = generic_lst_malloc_node(data_size);
	if (!new_node)
		return (1);
	new_node->content = ft_memcpy(new_node->content, data, data_size);
	ft_lstadd_back(lst, new_node);
	return (0);
}
