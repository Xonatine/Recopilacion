/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:57:27 by dgargant          #+#    #+#             */
/*   Updated: 2026/03/26 12:35:57 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vbc.h"

char *s;

void unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of file\n");
}

int ft_product()
{
	int a = ft_factor();
	int b;
	while (*s == '*')
	{
		s++;
		b = ft_factor();
		a = a * b;
	}
	return (a);
}

int ft_sum()
{
	int sum1 = ft_product();
	int sum2;
	while (*s == '+')
	{
		s++;
		sum2 = ft_product();
		sum1 = sum1 + sum2;
	}
	return (sum1);
}

int ft_factor()
{
	int n = 0;
	if (isdigit(*s))
		return(*s++ - '0');
	while (*s == '(')
	{
		s++;
		n = ft_sum();
		s++;
	}
	return (n);
}


int chek_imput(char *str)
{
	int par = 0;
	int i = 0;
	char last;
	while (str[i])
	{
		if (str[i] == '(')
			par++;
		else if (str[i] == ')')
			par--;
		else if (!isdigit(str[i]) && str[i] !=  '+' && str[i] != '*' && str[i] != '(' 
			&& str[i] != ')')
		{
			unexpected(str[i]);
			return (1);
		}
		if (isdigit(str[i] && isdigit(str[i + 1])))
		{
			unexpected(str[i +1]);
			return (1);
		}
		if (isdigit(str[i] && isdigit(str[i + 1])))
		{
			unexpected(str[i +1]);
			return (1);
		}
		last = str[i];
		i++;
	}
	if(par > 0)
	{
		unexpected('(');
		return (1);
	}
	if(par < 0)
	{
		unexpected(')');
		return (1);
	}
	if (last == '+' || last == '*')
	{
		unexpected(0);
		return(1);
	}
	return  (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (chek_imput(argv[1]))
		return (1);
	s = argv[1];
	int res = ft_sum();
	printf("%d\n", res);
	return (0);
}