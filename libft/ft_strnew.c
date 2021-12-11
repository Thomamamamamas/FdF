#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (i < size + 1)
	{
		*((char *)str + i) = (int) '\0';
		i++;
	}
	return (str);
}
/*
int	main()
{
	size_t	size = 5;
	ft_strnew(size);
	return (0);
}
*/
