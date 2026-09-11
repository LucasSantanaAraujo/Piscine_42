#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int main(void)
{
	char *string = "Hello 42!";
	
	printf("string = %s\nstring length = %d", string, ft_strlen(string));
	return (0);
}
