/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:31:49 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/12/22 16:35:20 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_words(const char *str, char c)
{
	int		i;
	int		number_words;

	number_words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			number_words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (number_words);
}

static char	*ft_create_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

static char	**ft_create_tab(char const *str, char c, int words, int i)
{
	int		j;
	char	**tab;
	int		index;

	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	index = 0;
	while (index < words)
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[j] && str[j] != c)
			j++;
		tab[index++] = ft_create_word(str, i, j);
		if (!tab[index - 1])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		i = j + 1;
	}
	tab[index] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	int		words;

	words = ft_count_words(str, c);
	return (ft_create_tab(str, c, words, 0));
}
