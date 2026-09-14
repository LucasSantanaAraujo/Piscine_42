/*

• Escreva uma função que mostre ’N’ ou ’P’ segundo o sinal do inteiro passado como
parâmetro. Se n for negativo, indique ’N’. Se n for positivo ou nulo, indique ’P’.

• Deve ser prototipada da seguinte maneira:
void ft_is_negative(int n);

*/



#include <unistd.h>

void ft_is_negative(int n) {
	char a = 'N';
	char b = 'P';
	if (n < 0) {
		write(1, &a, 1);
	}
	if (n >= 0) {
		write(1, &b, 1);
	}
}

int main() {
	ft_is_negative(-10);
	write(1, "\n", 1);
	ft_is_negative(0);
	write(1, "\n", 1);
	ft_is_negative(5);
	write(1, "\n", 1);
	return 0;
}
