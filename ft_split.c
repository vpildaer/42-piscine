/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpildaer <vpildaer@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:25:54 by vpildaer          #+#    #+#             */
/*   Updated: 2026/02/25 17:24:35 by vpildaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlenchr(char *str, int c)
{
	int	i;

	if (c == 0)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		while (*str)
		{
			if (*str == c)
				return (-1);
			str++;
		}
		return (-2);
	}
}

int	str_count(char *str, char *charset, int strlen)
{
	int	i;
	int	old_i;
	int	count;

	count = 0;
	i = 0;
	while (i < strlen)
	{
		while (i < strlen && ft_strlenchr(charset, str[i]) == -1)
			i++;
		old_i = i;
		while (i < strlen && ft_strlenchr(charset, str[i]) == -2)
			i++;
		if (i > old_i)
			count += 1;
	}
	return (count);
}

char	*str_sub(char *str, char *charset, int *i, int strlen)
{
	char	*res;
	int		j;
	int		old_i;

	while (*i < strlen && ft_strlenchr(charset, str[*i]) == -1)
		*i = *i + 1;
	old_i = *i;
	while (*i < strlen && ft_strlenchr(charset, str[*i]) == -2)
		*i = *i + 1;
	if (*i == old_i)
		return (NULL);
	res = malloc(sizeof(char) * (*i - old_i + 1));
	if (res == NULL)
		return (NULL);
	j = 0;
	*i = old_i;
	while (*i < strlen && ft_strlenchr(charset, str[*i]) == -2)
	{
		res[j] = str[*i];
		*i = *i + 1;
		j++;
	}
	res[j] = '\0';
	return (&res[0]);
}

char	**res_fill(char *str, char *charset, char **res, int strlen)
{
	int		i;
	int		j;
	int		str_index;
	char	*substr;

	i = 0;
	str_index = 0;
	while (i < strlen)
	{
		substr = str_sub(str, charset, &i, strlen);
		if (substr != NULL)
		{
			res[str_index] = malloc(ft_strlenchr(substr, 0) + 1);
			if (res == NULL)
				return (NULL);
			j = -1;
			while (j++ < ft_strlenchr(substr, 0))
				res[str_index][j] = substr[j];
			res[str_index][j] = '\0';
			str_index++;
		}
	}
	res[str_index] = NULL;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		strlen;
	int		count;
	char	**res;

	strlen = ft_strlenchr(str, 0);
	count = str_count(str, charset, strlen);
	res = malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	res = res_fill(str, charset, res, strlen);
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char s[] = "This is a test, a test for my split function.";
	char **split_strings = ft_split(s, " ,.");
	int i = 0;
	while (split_strings[i] != NULL)
	{
		printf("%s\n", split_strings[i]);	
		i++;
	}
	return (0);
}*/
