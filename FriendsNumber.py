def extract_digits(number):
    digits = []
    while number > 0:
        digits.append(number % 10)
        number //= 10
    return digits

def is_friend(a, b):
    a_digits = set(extract_digits(a))
    b_digits = set(extract_digits(b))
    return bool(a_digits & b_digits)

end = int(input("Enter the end value: "))  # Get user input for the 'end' value
counter = 0

for i in range(1, end):
    counter += sum(is_friend(i, j) for j in range(i + 1, end + 1))

print(f"{counter} friends found in the interval 1 .. {end}.")
