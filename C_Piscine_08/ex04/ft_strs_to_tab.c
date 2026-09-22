#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    char *cpy;
    int i;

    cpy = (char *) malloc(ft_strlen(str) + 1);
    if (cpy == NULL)
        return (NULL);
    i = 0;
    while (str[i])
    {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    struct s_stock_str *tab;
    int i;

    tab = (struct s_stock_str *) malloc((ac + 1) * sizeof(struct s_stock_str));
    if (tab == NULL)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        tab[i].str = av[i];
        tab[i].size = ft_strlen(av[i]);
        tab[i].copy = ft_strdup(av[i]);
        i++;
    }
    tab[i].str = 0;
    return (tab);
}