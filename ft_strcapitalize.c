/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpildaer <vpildaer@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:58:07 by vpildaer          #+#    #+#             */
/*   Updated: 2026/02/05 18:41:55 by vpildaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (check(str[0]) == 1)
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (check(str[i]) == 1 && check(str[i - 1]) == 0)
			str[i] = str[i] - 32;
		if (check(str[i]) == 2 && check(str[i - 1]) > 0)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
