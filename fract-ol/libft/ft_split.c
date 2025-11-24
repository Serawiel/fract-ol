/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:20:42 by cprot             #+#    #+#             */
/*   Updated: 2025/03/31 09:20:45 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_words(const char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*extract_word(const char *s, char c, unsigned int *i)
{
	unsigned int	start;
	unsigned int	j;
	char			*word;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = (char *)malloc(sizeof(char) * (*i - start + 1));
	if (!word)
		return (NULL);
	while (start + j < *i)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

void	free_tab(char **tab, unsigned int j)
{
	while (j > 0)
	{
		free(tab[j - 1]);
		j--;
	}
	free(tab);
}

char	**ft_split(const char *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		tab[j] = extract_word(s, c, &i);
		if (!tab[j])
			return (free_tab(tab, j), NULL);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
