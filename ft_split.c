/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:44:00 by mel-omar          #+#    #+#             */
/*   Updated: 2019/12/03 23:20:02 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int		number_words(char *str, char c)
{
	int				found;
	unsigned int	count;
	int				iter;

	count = 0;
	found = 1;
	iter = 0;
	while (str[iter] != '\0')
	{
		if (str[iter] == c)
			found = 1;
		else if (found)
		{
			count++;
			found = 0;
		}
		iter++;
	}
	return (count);
}

static unsigned int		*words_length(char *str, unsigned int length, char c)
{
	unsigned int	*words;
	unsigned int	iter;
	unsigned int	i;

	if (!(words = (unsigned int *)malloc(sizeof(unsigned int) * length)))
		return (NULL);
	iter = 0;
	i = 0;
	while (i < length)
	{
		words[i] = 0;
		while (str[iter] == c)
			iter++;
		while (str[iter] != '\0' && str[iter] != c)
		{
			words[i]++;
			iter++;
		}
		i++;
	}
	return (words);
}

static char				*substr(char *str, int start, int end)
{
	char	*sub;
	int		iter;

	if (!(sub = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	iter = 0;
	while (iter < end - start)
	{
		sub[iter] = str[start + iter];
		iter++;
	}
	sub[iter] = '\0';
	return (sub);
}

static char				**put_words(char *str, char c,
		unsigned int *words_l, unsigned int word_c)
{
	unsigned int	iter;
	unsigned int	it;
	char			**words;

	if (!(words = (char **)malloc(sizeof(char *) * (word_c + 1))))
		return (NULL);
	iter = 0;
	it = -1;
	while (++it < word_c)
	{
		while (str[iter] == c)
			iter++;
		if (!(words[it] = substr(str, iter, iter + words_l[it])))
		{
			while (it)
				free((words)[it--]);
			free(words);
			words = NULL;
			break ;
		}
		iter += words_l[it];
	}
	return (words);
}

char					**ft_split(char *str, char c)
{
	char			**words;
	unsigned int	words_c;
	unsigned int	*words_l;

	words_c = number_words(str, c);
	if (!(words_l = words_length(str, words_c, c)))
		return (NULL);
	if (!(words = put_words(str, c, words_l, words_c)))
		return (NULL);
	words[words_c] = NULL;
	return (words);
}
