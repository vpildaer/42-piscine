/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpildaer <vpildaer@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:56:21 by vpildaer          #+#    #+#             */
/*   Updated: 2026/02/07 17:45:26 by vpildaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((s1[i] || s2[i]) && res == 0 && n > 0)
	{
		res = ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
		n--;
	}
	return (res);
}
