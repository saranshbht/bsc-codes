def fib(n):
    a, b = 1, 1
    for i in range(0, n):
        print(a, end = ' ')
        a, b = b, a + b

n = int(input("Enter a number: "))
if n < 1:
    print("Please enter a positive number")
else:
    fib(n)
