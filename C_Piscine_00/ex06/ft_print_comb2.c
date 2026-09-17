/*

• Escreva uma função que mostre todas as diferentes combinações de dois números
(XX XX) entre 00 e 99, em ordem crescente.

• O resultado esperado seria:
$>./a.out | cat -e
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>

• Deve ser prototipada da seguinte maneira:
void ft_print_comb2(void);

*/

#include <unistd.h>

void ft_print_comb2(void)
{
   int a;
   int b;
   char c;

   a = 0;
   while (a <= 98)
   {
        b = a + 1;
        while (b <= 99)
        {
            c = (a / 10) + '0';
            write(1, &c, 1);

            c = (a % 10) + '0';
            write(1, &c, 1);

            write(1, " ", 1);

            c = (b / 10) + '0';
            write(1, &c, 1);

            c = (b % 10) + '0';
            write(1, &c, 1);

            if (a != 98 || b != 99)
                write(1, ", ", 2);
            b++;
        }
        a++;
   }

}

int main(void)
{
    ft_print_comb2();
    write(1, "\n", 1);
    return 0;
}