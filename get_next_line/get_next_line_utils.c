/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:10:49 by chael-ha          #+#    #+#             */
/*   Updated: 2020/01/19 23:50:21 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ptr = (char *)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

size_t		ft_strlen(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	l;
	char	*ptr;

	j = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(&s[start]);
	if (start > ((unsigned int)ft_strlen(s)))
		return (ft_strdup(""));
	if (l >= len)
		l = len;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (len + 1))))
		return (NULL);
	while (j < l && s[start])
	{
		ptr[j] = s[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (0);
}
