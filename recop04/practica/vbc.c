char *s;

int main (int argc, char **argv)
{
	int res;

	if (argc != 2)
		return (1);
	if (check_imput(argv[1]))
		return (1);
	s = argv[1];
	res = ft_sum();
	printf("%d\n", res);
	return (0);
}

void unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of file\n");
}

int ft_sum()
{
	int sum1 = ft_product();
	int sum2;

	while(*s == '+')
	{
		s++;
		sum2 = ft_product();
		sum1 = sum1 + sum2;
	}
	return (sum1);
}

int ft_product()
{
	int a = ft_factor();
	int b;
	while(*s == '*')
	{
		s++;
		b = ft_factor();
		a = a * b;
	}
	return (a);
}
int ft_factor()
{
	int n = 0;

	if (isdigit(*s))
		return (*s++ - '0');
	while(*s == '(')
	{
		s++;
		n = ft_sum();
		s++;
	}
	return (n);
}