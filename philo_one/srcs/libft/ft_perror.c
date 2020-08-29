/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:20:07 by frthierr          #+#    #+#             */
/*   Updated: 2020/08/29 13:54:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_perror(char *msg)
{
	char	*errmsg;

	errmsg = NULL;
	if (!(errmsg = ft_strjoin("Error: ", msg)))
		return (0);
	else
	{
		ft_putendl_fd(errmsg, 2);
		free(errmsg);
	}
	return (0);
}
