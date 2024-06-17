import numpy as np

# Коэффициенты системы
A = np.array([
    [-25, 4, -4, 9],
    [-9, 21, 5, -6],
    [9, 2, 19, -7],
    [-7, 4, -7, 25]
])

b = np.array([86, 29, 28, 68])

# Начальное приближение
x0 = np.zeros_like(b)

# Метод Зейделя
def seidel_method(A, b, x0, tolerance=1e-10, max_iterations=1000):
    n = len(b)
    x = x0.copy()
    x_new = np.zeros_like(x)
    iterations = 0
    error = tolerance + 1
    
    while error > tolerance and iterations < max_iterations:
        for i in range(n):
            sum_1 = np.dot(A[i, :i], x_new[:i])
            sum_2 = np.dot(A[i, i + 1:], x[i + 1:])
            x_new[i] = (b[i] - sum_1 - sum_2) / A[i, i]
        
        error = np.linalg.norm(x_new - x)
        x = x_new.copy()
        iterations += 1
    
    if iterations == max_iterations:
        raise RuntimeError("Метод Зейделя не сошелся.")
    
    return x

# Решение методом Зейделя
try:
    solution = seidel_method(A, b, x0)
    print("Решение методом Зейделя:")
    print(solution)
except RuntimeError as e:
    print(e)
