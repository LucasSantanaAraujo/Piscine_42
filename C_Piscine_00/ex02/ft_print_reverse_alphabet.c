/*

• Escreva uma função que mostre o alfabeto em minúsculo, numa única linha, em
ordem decrescente, começando pela letra ’z’.

• Deve ser prototipada da seguinte maneira:
void ft_print_reverse_alphabet(void);

*/


#include <unistd.h>

void ft_print_reverse_alphabet(void) {
	char c = 'z';

	while (c >= 'a') {
		write(1, &c, 1);
		c--;
	}
}

int main() {
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	return 0;
}
