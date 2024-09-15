#include "cube.h"

void	ft_lstdelone_collec(t_colec *lst)
{
	if (!lst)
		return ;
	free(lst->ptr);
	lst->ptr = NULL;
	free(lst);
	lst = NULL;
}

void	ft_lstclear_collec(t_colec **lst)
{
	t_colec	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_collec(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_colec	*ft_lstlast_collec(t_colec *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_collec(t_colec **lst, t_colec *new)
{
	t_colec	*ptr_node;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		ptr_node = ft_lstlast_collec(*lst);
		ptr_node->next = new;
	}
	else
		*lst = new;
}

// printf("address of name : %s add in collectore : %p  \n" , str ,  ptr);
void	ft_collectore(t_cube *data, void *ptr, char *str)
{
	t_colec *node;
	t_colec *head;

	(void)str;
	if (ptr == NULL)
	{
		write(2, "Error In Game\n", 15);
		ft_lstclear_collec(&data->list_collecte_head);
	}
	head = malloc(sizeof(t_colec));
	if (!head)
	{
		write(2, "Error In Game\n", 15);
		ft_lstclear_collec(&data->list_collecte_head);
		exit(1);
	}
	head->ptr = ptr;
	head->next = NULL;
	node = head;
	ft_lstadd_back_collec(&data->list_collecte_head, node);
}