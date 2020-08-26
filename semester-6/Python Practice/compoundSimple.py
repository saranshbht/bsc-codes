def compound(p, r, t):
    return p * (1 + r / 100) ** t - p

def simple(p, r, t):
    return p * r * t / 100

while True:
    print()
    p = float(input("Enter principal amount: "))
    r = float(input("Enter rate of interest: "))
    t = float(input("Enter time(in years): "))

    print("1.Simple Interest")
    print("2.Compound Interest")
    print("0.Exit")
    choice = int(input("Enter your choice: "))
                 
    if choice == 1:
        print("Simple interest:", simple(p, r, t))
    elif choice == 2:
        print("Compound interest:", compound(p, r, t))
    else:
        break


