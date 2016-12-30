/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:29:44 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/07 18:30:32 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*pn;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	p = lst;
	pn = f(p);
	if (pn == NULL)
		return (NULL);
	new = pn;
	p = p->next;
	while (p)
	{
		pn->next = f(p);
		if (pn->next == NULL)
			return (NULL);
		p = p->next;
		pn = pn->next;
	}
	pn->next = NULL;
	return (new);
}
