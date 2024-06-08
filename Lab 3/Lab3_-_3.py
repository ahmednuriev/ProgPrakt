def numerical_series(epsilon):
    sum_value = 0
    k = 1
    term = 1  # Initialize term to enter the loop
    while abs(term) > epsilon:
        term = 15 / (2**(k - 1)) + ((-1)**(k - 1)) / (2 * 3**(k - 1))
        sum_value += term
        k += 1
    return sum_value

epsilon = 1e-6
result = numerical_series(epsilon)
print(f"Sum of the numerical series with epsilon {epsilon}: {result}")
