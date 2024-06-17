import numpy as np

# Заданные точки
x = np.array([0.1*np.pi, 0.2*np.pi, 0.3*np.pi, 0.4*np.pi])
y = np.cos(x)

# Функция для вычисления разделённых разностей
def divided_diff(x, y):
    n = len(y)
    coef = np.zeros(n)
    for i in range(n):
        coef[i] = y[i]
    for j in range(1, n):
        for i in range(n-1, j-1, -1):
            coef[i] = (coef[i] - coef[i-1]) / (x[i] - x[i-j])
    return coef

# Функция для вычисления значения интерполяционного многочлена Ньютона в точке x
def newton_interpolation(x, xi, yi):
    n = len(xi) - 1
    coef = divided_diff(xi, yi)
    result = coef[n]
    for i in range(n-1, -1, -1):
        result = result * (x - xi[i]) + coef[i]
    return result

# Точка, в которой нужно вычислить значение интерполяционного многочлена
x_eval = 0.25*np.pi
P_x_eval = newton_interpolation(x_eval, x, y)

print(f"Значение интерполяционного многочлена Ньютона в точке x = 0.25*pi: {P_x_eval}")

# Точное значение функции в точке x_eval
exact_value = np.cos(x_eval)
print(f"Точное значение функции в точке x = 0.25*pi: {exact_value}")

# Вычисление погрешности интерполяции
error = np.abs(exact_value - P_x_eval)
print(f"Погрешность интерполяции в точке x = 0.25*pi: {error}")
