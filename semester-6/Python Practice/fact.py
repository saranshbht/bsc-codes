def  fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

n = int(input("Enter a number: "))
if n < 0:
    print("Enter a non-negative integer")
else:
    print(str(n) + "! =", fact(n))
