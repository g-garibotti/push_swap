/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:50:15 by ggaribot          #+#    #+#             */
/*   Updated: 2024/06/06 18:15:28 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_map(t_list *map, void (*del)(void *))
{
	t_list	*tmp;

	while (map)
	{
		tmp = map->next;
		ft_lstdelone(map, del);
		map = tmp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_elem;
	void	*transformed_content;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		transformed_content = f(lst->content);
		new_elem = ft_lstnew(transformed_content);
		if (!new_elem)
		{
			del(transformed_content);
			free_map(map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_elem);
		lst = lst->next;
	}
	return (map);
}
