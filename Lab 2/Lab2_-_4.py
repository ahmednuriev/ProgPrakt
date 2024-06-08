import random
import math
import numpy as np

# Генерация случайных параметров гиперболоида
a = random.uniform(1, 10)
b = random.uniform(1, 10)
c = random.uniform(1, 10)

# Уравнение гиперболоида: x^2 / a^2 - y^2 / b^2 - z^2 / c^2 = 1

# Случайная плоскость: Ax + By + Cz + D = 0
A = random.uniform(-10, 10)
B = random.uniform(-10, 10)
C = random.uniform(-10, 10)
D = random.uniform(-10, 10)

# Случайная прямая: (x, y, z) = (x0, y0, z0) + t(dx, dy, dz)
x0 = random.uniform(-10, 10)
y0 = random.uniform(-10, 10)
z0 = random.uniform(-10, 10)
dx = random.uniform(-10, 10)
dy = random.uniform(-10, 10)
dz = random.uniform(-10, 10)

# Случайная точка
px = random.uniform(-20, 20)
py = random.uniform(-20, 20)
pz = random.uniform(-20, 20)

# Проверка принадлежности точки гиперболоиду
def is_point_on_hyperboloid(a, b, c, x, y, z):
    return (x**2 / a**2) - (y**2 / b**2) - (z**2 / c**2) <= 1

# Проверка пересечения плоскости и гиперболоида
def does_plane_intersect_hyperboloid(a, b, c, A, B, C, D):
    # Проверка дискриминанта при подстановке плоскости в уравнение гиперболоида
    delta = B**2 - 4 * A * (C - A**2)
    return delta >= 0

# Проверка пересечения прямой и гиперболоида
def does_line_intersect_hyperboloid(a, b, c, x0, y0, z0, dx, dy, dz):
    A = (dx**2 / a**2) - (dy**2 / b**2) - (dz**2 / c**2)
    B = 2 * ((x0 * dx / a**2) - (y0 * dy / b**2) - (z0 * dz / c**2))
    C = (x0**2 / a**2) - (y0**2 / b**2) - (z0**2 / c**2) - 1
    discriminant = B**2 - 4 * A * C
    return discriminant >= 0

# Результаты
point_on_hyperboloid = is_point_on_hyperboloid(a, b, c, px, py, pz)
plane_intersects = does_plane_intersect_hyperboloid(a, b, c, A, B, C, D)
line_intersects = does_line_intersect_hyperboloid(a, b, c, x0, y0, z0, dx, dy, dz)

# Вывод результатов
print(f"Hyperboloid: x^2 / {a**2} - y^2 / {b**2} - z^2 / {c**2} = 1")
print(f"Plane: {A}x + {B}y + {C}z + {D} = 0")
print(f"Line: (x, y, z) = ({x0}, {y0}, {z0}) + t({dx}, {dy}, {dz})")
print(f"Point: ({px}, {py}, {pz})")
print(f"Point on hyperboloid: {'Yes' if point_on_hyperboloid else 'No'}")
print(f"Plane intersects hyperboloid: {'Yes' if plane_intersects else 'No'}")
print(f"Line intersects hyperboloid: {'Yes' if line_intersects else 'No'}")
