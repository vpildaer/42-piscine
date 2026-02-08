/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpildaer <vpildaer@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:00:56 by vpildaer          #+#    #+#             */
/*   Updated: 2026/02/08 12:33:48 by vpildaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	tofill;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	tofill = size - dlen - 1;
	if (dlen >= size)
		return (size + slen);
	while (src[i] && tofill > 0)
	{
		dest[dlen + i] = src[i];
		i++;
		tofill--;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
