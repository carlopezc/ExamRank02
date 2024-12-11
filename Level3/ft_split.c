/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:43:54 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/11 20:14:51 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_count_words(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13) || str[i] == '\0'))
		{
			count++;
			while (str[i] && (!((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))))
				i++;
		}
	}
	return (count);
}

int	ft_count_letters(char *str, int *start)
{
	int	letters;

	letters = 0;
	while (str[*start] && ((str[*start] == 32) || (str[*start] >= 9 && str[*start] <= 13)))
		(*start)++;
	while (str[*start] && (!((str[*start] == 32) || (str[*start] >= 9 && str[*start] <= 13))))
	{
		letters++;
		(*start)++;
	}
	return (letters);
}

char	*ft_fill_word(char *str, int *start)
{
	char	*word;
	int	letters;
	int	i;
	int	tmp_start;

	if (!str)
		return (NULL);
	tmp_start = *start;
	letters = ft_count_letters(str, start);
	word = (char *)malloc(letters + 1 * sizeof(char));
	if (!word)
		return (NULL);
	word[letters] = '\0';
	while (str[tmp_start] && (str[tmp_start] == 32 || (str[tmp_start] >= 9 && str[tmp_start] <= 13)))
		tmp_start++;
	i = 0;
	while (str[tmp_start] && (!(str[tmp_start] == 32 || (str[tmp_start] >= 9 && str[tmp_start] <= 13))))
		word[i++] = str[tmp_start++];
	return (word);
}

void	ft_free(char **words, int i)
{
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
	return ;
}

char	**ft_split(char *str)
{
	int	nword;
	char	**words;
	int	start;
	int	i;

	if (!str)
		return (NULL);
	nword = ft_count_words(str);
	words = (char **)malloc((nword + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[nword] = NULL;
	start = 0;
	i = 0;
	while (i < nword)
	{
		words[i] = ft_fill_word(str, &start);
		if (!words[i])
			return (ft_free(words, i), NULL);
		i++;
	}
	return (words);
}
/*
int	main(void)
{
	char	**words;
	int	i;

	words = ft_split(" ");
	if (!words)
		return (printf("no ha devuelto bien split"), 1);
	i = 0;
	if (!words[0])
		printf("Aqui no hay na");
	while (words && words[i])
	{
		printf("%s\n", words[i]);
		i++;
	}
	return (0);
}
*/
