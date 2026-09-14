/*

• Escreva uma função que mostre o caractere passado como parâmetro.

• Deve ser prototipada da seguinte maneira:
void ft_putchar(char c);

Para mostrar o caractere, deve usar a função write da seguinte maneira
write(1, &c, 1);

*/ 


#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

int main() {
	ft_putchar('A');
	write(1, "\n", 1);
	return 0;
}
