import math


def bisection_method(func, left, right, epsilon=1e-6):
    midpoint = (left + right) / 2
    if abs(func(midpoint)) < epsilon:
        return midpoint
    elif func(left) * func(midpoint) < 0:
        return bisection_method(func, left, midpoint, epsilon)
    else:
        return bisection_method(func, midpoint, right, epsilon)


def f(x):
    return math.exp(x - 1) - x ** 3 - x


left = 0
right = 10

root = bisection_method(f, left, right)
print(f"Корень уравнения: {root}")
