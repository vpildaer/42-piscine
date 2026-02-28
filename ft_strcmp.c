/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpildaer <vpildaer@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:41:25 by vpildaer          #+#    #+#             */
/*   Updated: 2026/02/07 16:44:24 by vpildaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((s1[i] || s2[i]) && res == 0)
	{
		res = ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (res);
}
