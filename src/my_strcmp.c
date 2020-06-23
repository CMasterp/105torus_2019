/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int res = 0;

    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        res += (s1[i] - s2[i]);
        if (res < 0 || res > 0)
            return (res);
    }
    return (res);
}
