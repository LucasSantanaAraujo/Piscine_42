/*

• Escreva uma função que mostre o alfabeto em minúsculo, numa única linha, em
ordem crescente, começando pela letra ’a’.

• Deve ser prototipada da seguinte maneira:
void ft_print_alphabet(void);

*/ 


#include <unistd.h>

void ft_print_alphabet(void) {
	char c = 'a';

	while(c <= 'z') {
		write(1, &c, 1);
		c++;	
	}
}

int main() {
	ft_print_alphabet();
	write(1, "\n", 1);
	return 0;
}
