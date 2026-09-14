/*

• Escreva uma função que mostre, em ordem crescente, todas as diferentes combinações 
de três números diferentes em ordem crescente - sim, a repetição é intencional.

• O resultado esperado seria:
$>./a.out | cat -e

012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>

• 987 fica de fora porque 789 já está presente
• 999 fica de fora porque o dígito 9 aparece mais de uma vez.

• Deve ser prototipada da seguinte maneira:
void ft_print_comb(void);

*/


#include <unistd.h>

void ft_print_comb(void) {
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '7') {
		b = a + 1;

		while (b <= '8') {
			c = b + 1;

			while (c <= '9') {
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);

				if (a != '7' || b != '8' || c != '9') {
					write(1, ", ", 2);
				}

				c++;
			}

			b++;
		}

		a++;
	}
}

int main() {
	ft_print_comb();
	write(1, "\n", 1);
	return 0;
}
