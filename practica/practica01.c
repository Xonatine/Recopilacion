#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strjoin(char *s1, char *s2)
{
	char *join;
	char *result;

	join = malloc(strlen(s1) + strlen(s2) + 1);
	if (!join)
		return (NULL);
	result = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (result);
}

void ft_replace(char **str, char *argv)
{
	char	*new_str = malloc(strlen(*str) + 1);
	size_t	len = strlen(argv);
	if (!new_str)
	{
		free(*str);
		perror("Error: ");
		exit(1);
	}
	char *src = *str;
	char *dst = new_str;
	while (*src)
	{
		size_t i = 0;
		while (argv[i] && src[i] == argv[i])
			i++;
		if (i == len)
		{
			for (size_t j = 0; j < len; j++)
				*dst++ = '*';
			src += len;
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	free(*str);
	*str = new_str;
}

int main(int argc, char **argv)
{
	char *str;
	char *dest;
	char *temp;
	ssize_t linea;

	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	str = calloc(1,1);
	if (!str)
	{
		perror("Error: ");
		return (1);
	}
	dest = malloc((size_t)BUFFER_SIZE +1);
	if (!dest)
	{
		free(str);
		perror("Error: ");
		return (1);
	}
	linea = 1;
	while (linea > 0)
	{
		linea = read(0, dest, BUFFER_SIZE);
		if (linea == -1)
		{
			free(str);
			free(dest);
			perror("Error: ");
			return (1);
		}
		dest[linea] = '\0';
		temp = ft_strjoin(str, dest);
		if (!temp)
		{
			free(str);
			free(dest);
			perror("Error: ");
			return (1);
		}
		free(str);
		str = temp;
	}
	free(dest);
	ft_replace(&str, argv[1]);
	printf("%s", str);
	free(str);
	return(0);
}