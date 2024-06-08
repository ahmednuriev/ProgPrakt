import random
import math

# Генерация случайных параметров эллипса
a = random.uniform(1, 10)  # Большая полуось
b = random.uniform(1, 10)  # Малая полуось

# Центр эллипса в точке (h, k)
h = random.uniform(-10, 10)
k = random.uniform(-10, 10)

# Случайная точка (x, y)
x = random.uniform(-20, 20)
y = random.uniform(-20, 20)

# Проверка принадлежности точки эллипсу
def is_point_on_ellipse(a, b, h, k, x, y):
    return ((x - h)**2 / a**2) + ((y - k)**2 / b**2) <= 1

# Вычисление координат фокусов эллипса
def ellipse_foci(a, b, h, k):
    c = math.sqrt(abs(a**2 - b**2))
    if a > b:
        f1 = (h + c, k)
        f2 = (h - c, k)
    else:
        f1 = (h, k + c)
        f2 = (h, k - c)
    return f1, f2

# Вычисление эксцентриситета эллипса
def ellipse_eccentricity(a, b):
    return math.sqrt(1 - min(a, b)**2 / max(a, b)**2)

# Вычисление расстояния от директрис эллипса до его центра
def ellipse_directrices(a, b):
    if a > b:
        return a / math.sqrt(a**2 - b**2)
    else:
        return b / math.sqrt(b**2 - a**2)

# Результаты
point_on_ellipse = is_point_on_ellipse(a, b, h, k, x, y)
f1, f2 = ellipse_foci(a, b, h, k)
eccentricity = ellipse_eccentricity(a, b)
directrix_distance = ellipse_directrices(a, b)

# Вывод результатов
print(f"Ellipse: (x - {h})^2 / {a**2} + (y - {k})^2 / {b**2} = 1")
print(f"Point: ({x}, {y})")
print(f"Point on ellipse: {'Yes' if point_on_ellipse else 'No'}")
print(f"Foci: F1{f1}, F2{f2}")
print(f"Lengths of semi-axes: a = {a}, b = {b}")
print(f"Eccentricity: {eccentricity}")
print(f"Distance from center to directrices: {directrix_distance}")
