/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Counts and returns the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i]; i++);
    return (i);
}
