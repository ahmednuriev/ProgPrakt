import math

def functional_series(x, epsilon):
    sum_value = 0
    k = 1
    term = 1  # Initialize term to enter the loop
    while abs(term) > epsilon:
        term = ((-1)**k) / (math.sin(k * x) + 15 + k**2)
        sum_value += term
        k += 1
    return sum_value

x = 1  # Choose an arbitrary value for x
epsilon = 1e-6
result = functional_series(x, epsilon)
print(f"Sum of the functional series with x={x} and epsilon={epsilon}: {result}")
