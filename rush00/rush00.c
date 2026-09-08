void ft_putchar(char c);

void ft_print_line(int x, char left_char, char middle_char, char right_char)
{
		int current_char;

		ft_putchar(left_char);
		current_char = 2;

		while (current_char < x)
		{
				ft_putchar(middle_char);
				current_char++;
		}
		if (x > 1)
				ft_putchar(right_char);
		ft_putchar('\n');
}

void rush(int x, int y)
{
		int current_line;

		current_line = 1;

		while (current_line <= y)
		{
				if (current_line == 1 || current_line == y)
						ft_print_line(x, 'o', '-', 'o');
				else
						ft_print_line(x, '|', ' ', '|');

				current_line++;
		}
}
