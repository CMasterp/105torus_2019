# 105torus - Image synthesis software

- **Binary name:** 105torus
- **Repository name:** 105torus_2019
- **Repository rigths:** ramassage-tek
- **Language:** C, C++, perl 5, python 3 (>= 3.5), ruby 2 (>= 2.2), php 5.6, bash 4 and everything working on "the dump"
- **Choosed language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

Drawing circles, cylinders and cones is a good start for an image synthesis software, but one have to admit
it is not fully satisfying. . . This project is the continuation of the previous one, and should allow you to draw
more complex forms, such as a torus, which do not emerge from 2nd degree equations, but from superior
degree equations (4th degree in the torus case).

The objective of this project is to solve a 4th degree equation: ax⁴ + bx³ + cx² + dx + e = 0.

A direct resolution method does exist (Ferrari’s method), but does not generalize to higher degrees. Thus, we will
rather compare 3 iterative algorithms:
       • The bisection method,
       • Newton’s method,
       • The secant method.

## Nao Marvin

| Details      | Nao Marvin :robot: (%) |
| ------------- |:-------------:|
| `rigor`: 100% \| `basic`: 100% \| `option 1`: 100% \| \| `option 2`: 100% \| `option 3`: 33.3% \| `mathematical rigor`: 100% | 88.6% |

## Prerequisites

What you need

```
GlibC
gcc
make
```

## Compiling

Clone the repository and go inside. Then,

```
$ make
```

## Usage

```
~/B-MAT-100> ./105torus opt a0 a1 a2 a3 a4 n
```

- **opt (method option):**
				• 1 for the bisection method
				• 2 for Newton’s method
				• 3 for the secant method
- **a[0-4]:** coefficients of the equation
- **n:** precision (the application of the polynomial to the solution should be smaller than 10^-n)

## Examples

```
∼/B-MAT-100> ./105torus 1 -1 0 6 -5 1 6
x = 0.5
x = 0.75
x = 0.625
x = 0.5625
x = 0.53125
x = 0.515625
x = 0.523438
x = 0.519531
x = 0.521484
x = 0.522461
x = 0.522949
x = 0.522705
x = 0.522827
x = 0.522766
x = 0.522736
x = 0.522751
x = 0.522743
x = 0.522739
x = 0.522741
x = 0.522740
```

```
∼/B-MAT-100> ./105torus 2 -1 0 6 -5 1 12
x = 0.5
x = 0.522727272727
x = 0.522740003514
x = 0.522740003526
```

```
∼/B-MAT-100> ./105torus 3 -1 0 6 -5 1 8
x = 0.5
x = 0.52941176
x = 0.52274853
x = 0.52274000
x = 0.52274000
```
> :bulb: Mind the float numbers precision!