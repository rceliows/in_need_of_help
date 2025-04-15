#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	separator_count(char *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		if (*s == c)
			n++;
		if (*s)
			s++;
	}
	return (n);
}

static char	*copy_word(char *start, char *end)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = end - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free(word);
		return (NULL);
	}
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	split_string(char *s, char c, char **results)
{
	int		i;
	char	*start;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			results[i] = copy_word(start, s);
			if (!results[i])
			{
				return ;
			}
			i++;
		}
	}
	results[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**results;

	if (c == '\0' || !s)
		return (NULL);
	n = separator_count((char *)s, c);
	results = (char **)malloc(sizeof(char *) * (n + 2));
	if (!results)
	{
		n = 0;
		while (results[n])
		{
			free(results[n]);
			n++;
		}
		return (NULL);
	}
	split_string((char *)s, c, results);
	return (results);
}

int main(void)
{
	char	**result;
	int		i;

	result = ft_split("hello world this is a test", ' ');
	if (!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	for (i = 0; result[i]; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}
