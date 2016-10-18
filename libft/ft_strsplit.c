/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:55:25 by mbompoil          #+#    #+#             */
/*   Updated: 2016/07/18 15:26:23 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_numwords(const char *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			res++;
		i++;
	}
	return (res);
}

static size_t		ft_splits(char **str, const char *s, char c, size_t i)
{
	size_t	n;
	size_t	len;

	n = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			if ((str[n] = ft_strsub(s, i - len, len)) == NULL)
				return (-1);
			n++;
			len = 0;
		}
		else
			i++;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	n;

	str = NULL;
	n = (ft_numwords(s, c));
	if ((str = (char **)malloc((n + 1) * sizeof(char *))) == NULL)
		return (NULL);
	ft_splits(str, s, c, 0);
	str[n] = NULL;
	return (str);
}
