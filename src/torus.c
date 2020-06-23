/*
** EPITECH PROJECT, 2020
** torus
** File description:
** torus
*/

#include "../include/my.h"

double abs_val(double a)
{
    if (a < 0)
        return (-a);
    else
        return (a);
}

double pow2(double n)
{
    double tn = 0;
    if (n >= 0) {
        tn = pow(10, n);
        return (1 / tn);
    } else {
        tn = pow(10, -n);
        return (tn);
    }
}

double my_pow(double x, int n)
{
    double y = 1;
    for (n; n > 0; n--)
        y *= x;
    return (y);
}

double x_image_prime(t_coef val, double x)
{
    double y = val.a4 * my_pow(x, 3) * 4;
    y += val.a3 * my_pow(x, 2) * 3;
    y += val.a2 * my_pow(x, 1) * 2;
    y += val.a1;
    return (y);
}

double x_image(t_coef val, double x)
{
    double y = val.a4 * my_pow(x, 4);
    y += val.a3 * my_pow(x, 3);
    y += val.a2 * my_pow(x, 2);
    y += val.a1 * x;
    y += val.a0;
    return (y);
}

double bisec(t_coef val, double a, double b)
{
    double res = 0;
    double c = (a + b) / 2;
    double fc = x_image(val, c);
    if (c < 0 || c > 1)
        exit(84);
    if (abs_val(fc) > pow2(val.n)) {
        printf("x = %.*g\n", (int)val.n, c);
        if ((x_image(val, a) * fc) < 0)
            res = bisec(val, a, c);
        else
            res = bisec(val, c, b);
    } else
        return (c);
    return (res);
}

double newton(t_coef val)
{
    double xn = 0.5;
    double xn1 = 0;
    double fxn = 0;
    double fxn1 = 1;
    double fxn_prime = 0;
    int a = 0;

    printf("x = 0.5\n");
    for (; a == 0 || xn == 0.5;) {
        fxn = x_image(val, xn);
        fxn_prime = x_image_prime(val, xn);
        xn1 = (xn - (fxn / fxn_prime));
        fxn1 = fabs(x_image(val, xn1));
        if (xn1 < 0 || xn1 > 1)
            exit(84);
        if ((fxn1 > pow2(val.n)))
            printf("x = %.*g\n", (int)val.n, xn1);
        else
            break;
        xn = xn1;
    }
    printf("x = %.*f\n", (int)val.n, xn1);
}

double secant(t_coef val, double xnm, double xn)
{
    double fxn = x_image(val, xn);
    double fxnm = x_image(val, xnm);
    double xn1 = xn - ((fxn * (xn - xnm)) / (fxn - fxnm));

    if (xn1 < 0 || xn1 > 1)
        exit(84);
    if (abs_val(x_image(val, xn1)) > pow2(val.n)) {
        if (xn1 != 0.5)
            printf("x = %.*f\n", (int)val.n, xn1);
        else
            printf("x = 0.5\n");
        xn1 = secant(val, xn, xn1);
    }  else
        return (xn1);
    return (xn1);
}

int check_re(t_coef val, int opt)
{
    double a = 0;
    double b = 1;
    double fa = x_image(val, a);
    double fb = x_image(val, b);
    if (fa > 0 && fb > 0)
        exit(84);
    else if (fa < 0 && fb < 0)
        exit(84);
    if (fa == 0 && opt == 1) {
        printf("x = 0\n");
        exit(0);
    }
    else if (fb == 0 && opt == 1) {
        printf("x = 1\n");
        exit(0);
    }
}

int torus(t_coef val, int opt)
{
    double res = 0;
    check_re(val, opt);
    switch (opt) {
    case 1: res = bisec(val, 0, 1);
        if (res != 0.5)
            printf("x = %.*f\n", (int)val.n, res);
        else
            printf("x = 0.5\n");
        break;
    case 2: newton(val);
        break;
    case 3: res = secant(val, 0, 1);
        if (res != 0.5)
            printf("x = %.*f\n", (int)val.n, res);
        else
            printf("x = 0.5\n");
        break;
    default:
        break;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac != 8)
        return (84);
    check_arg(ac, av);
    torus((t_coef){atof(av[2]), atof(av[3]), atof(av[4]),
                atof(av[5]), atof(av[6]), atof(av[7])}, atoi(av[1]));
    return (0);
}
