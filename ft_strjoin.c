/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpildaer <vpildaer@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:46:29 by vpildaer          #+#    #+#             */
/*   Updated: 2026/02/17 20:01:25 by vpildaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_reslen(int size, char **strs, char *sep)
{
	int	i;
	int	reslen;

	i = 0;
	reslen = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		reslen += ft_strlen(strs[i]);
		i++;
	}
	return (reslen);
}

char	*res_fill(int size, char **strs, char *sep, int reslen)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	res = malloc(reslen + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (j++ < size - 1)
	{
		k = 0;
		while (strs[j][k] && i++ < reslen)
			res[i] = strs[j][k++];
		k = 0;
		while (sep[k] && i++ < reslen)
			res[i] = sep[k++];
	}
	res[reslen] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		reslen;
	char	*res;

	if (size == 0)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	reslen = ft_reslen(size, strs, sep);
	res = res_fill(size, strs, sep, reslen);
	if (res == NULL)
		return (NULL);
	return (res);
}
