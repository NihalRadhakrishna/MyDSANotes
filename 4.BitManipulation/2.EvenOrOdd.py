def is_even(number: int) -> bool:
    # The least significant bit is 0 for even numbers and 1 for odd numbers.
    return (number & 1) == 0


number = 10

if is_even(number):
    print(f"{number} is even")
else:
    print(f"{number} is odd")


# Time complexity: O(1)
# Space complexity: O(1)
