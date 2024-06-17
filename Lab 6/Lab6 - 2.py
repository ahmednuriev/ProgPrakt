import numpy as np

# Функция для вычисления значения функции f(x1, x2)
def f(x1, x2):
    return x1**2 + np.exp(x1**2 + x2**2) + 4*x1 + 3*x2

# Функция для вычисления градиента функции f(x1, x2)
def gradient_f(x1, x2):
    df_dx1 = 2*x1 + 2*x1*np.exp(x1**2 + x2**2) + 4
    df_dx2 = 2*x2*np.exp(x1**2 + x2**2) + 3
    return np.array([df_dx1, df_dx2])

# Функция для наискорейшего спуска
def steepest_descent(initial_x, alpha, epsilon, max_iter):
    x = initial_x
    iter = 0
    
    while True:
        grad = gradient_f(x[0], x[1])
        direction = -grad
        alpha_opt = alpha  # оптимальный шаг
        
        # Делаем шаг в направлении антиградиента
        x_next = x + alpha_opt * direction
        
        # Проверяем критерий останова
        if np.linalg.norm(x_next - x) < epsilon or iter >= max_iter:
            break
        
        x = x_next
        iter += 1
    
    return x, f(x[0], x[1])

# Начальное приближение и параметры метода
initial_x = np.array([0.0, 0.0])  # начальное приближение
alpha = 0.1  # коэффициент шага
epsilon = 1e-6  # критерий останова
max_iter = 1000  # максимальное число итераций

# Применение метода наискорейшего спуска
optimal_x, min_value = steepest_descent(initial_x, alpha, epsilon, max_iter)

# Вывод результатов
print("Минимум функции f найден в точке:")
print(f"x1 = {optimal_x[0]}")
print(f"x2 = {optimal_x[1]}")
print(f"Значение функции f(x1, x2) в этой точке: {min_value}")
