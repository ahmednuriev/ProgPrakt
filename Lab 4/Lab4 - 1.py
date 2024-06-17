import numpy as np

# Коэффициенты системы
A = np.array([
    [-7, -2, -1, -4],
    [-4, 6, 0, -4],
    [-8, 2, -9, -3],
    [0, 0, -7, 1]
])

b = np.array([-12, 22, 51, 49])

# Метод обратной матрицы
def inverse_matrix_method(A, b):
    A_inv = np.linalg.inv(A)
    x = np.dot(A_inv, b)
    return x

# Метод Гаусса
def gauss_method(A, b):
    A = A.astype(float)
    b = b.astype(float)
    n = len(b)

    # Прямой ход
    for i in range(n):
        max_row = i + np.argmax(np.abs(A[i:, i]))
        if A[max_row, i] == 0:
            raise ValueError("Матрица вырожденная")

        # Swap rows
        A[[i, max_row]] = A[[max_row, i]]
        b[[i, max_row]] = b[[max_row, i]]

        for j in range(i + 1, n):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            b[j] -= factor * b[i]

    # Обратный ход
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1:], x[i + 1:])) / A[i, i]

    return x

# Решение методом обратной матрицы
x_inverse = inverse_matrix_method(A, b)
print("Решение методом обратной матрицы:")
print(x_inverse)

# Решение методом Гаусса
x_gauss = gauss_method(A, b)
print("\nРешение методом Гаусса:")
print(x_gauss)
