#include "push_swap.h"

int	is_valid_number(char *str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > LONG_MAX && sign == 1)
			return (-1);
		if (result > LONG_MAX && sign == -1)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}
int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size - 1 > i)
	{
		j = i + 1;
		while (size > j)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	count_numbers(char **argv)
{
	int i;
	int count;
	i = 0;
	while (argv[i])
	{
		count = 0;
		if (is_valid_number(argv[i]))
			count++;
		i++;
	}
	return (count);
}
int *parse_input(char **argv, int *size)
{
	int i;
	int j;
	int *arr;
	i = 0;
	*size = count_numbers(argv);
	if (*size == 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * *size);
	if (!arr)
		return (NULL);
	j = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]))
		{
			arr[j] = ft_atoi(argv[i]);
			j++;
		}
		i++;
	}
	if (has_duplicates(arr, *size))
	{
		free(arr);
		arr = NULL;
		return (NULL);
	}
	return (arr);
}
void free_array(char **arr)
{
	int i;
	if(!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}