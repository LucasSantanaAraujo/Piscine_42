#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
	char *start;

	start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (start);
}

int main(void)
{
	char destination[] = "";
	char source[] = "Hello";
	char *result;

	printf("Destination = %s\nSource = %s\n", destination, source);

	result = ft_strcpy(destination, source);

	printf("result = %s", destination);
	return (0);
}
