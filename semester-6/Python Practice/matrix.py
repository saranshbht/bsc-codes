def addition(a, b):
    if len(a) != len(b) or len(a[0]) != len(b[0]):
        return "Addition not possible"
    c = []
    for i in range(0, len(a)):
        temp = []
        for j in range(len(a[0])):
            temp.append(a[i][j] + b[i][j])
        c.append(temp)
    return c

def subtraction(a, b):
    if len(a) != len(b) or len(a[0]) != len(b[0]):
        return "Subtraction not possible"
    c = []
    for i in range(0, len(a)):
        temp = []
        for j in range(len(a[0])):
            temp.append(a[i][j] - b[i][j])
        c.append(temp)
    return c

def transpose(a):
    c = []
    for i in range(len(a[0])):
        temp = []
        for j in range(len(a)):
            temp.append(a[j][i])
        c.append(temp)
    return c

def multiplication(a, b):
    if len(a[0]) != len(b):
        return "Multiplication not possible"
    c = []
    for i in range(len(a)):
        temp = []
        for j in range(len(b[0])):
            total = 0
            for k in range(len(b)):
                total += a[i][k] * b[k][j]
            temp.append(total)
        c.append(temp)
    return c

def inputMatrix():
    a = []
    n1 = int(input("Enter number of rows of matrix: "))
    m1 = int(input("Enter number of columns of matrix: "))
    print("Enter matrix")
    for i in range(n1):
        temp = []
        for j in range(m1):
            temp.append(int(input()))
        a.append(temp)
    return a

def printMatrix(res):
    for i in res:
        for j in i:
            print(j, end = ' ')
        print()

if __name__ == "__main__":        
    while True:
        print("Menu")
        print("1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n0.Exit")
        choice = int(input("Enter your choice: "))

        if choice == 0:
            break
        elif choice == 1:
            a = inputMatrix()
            print("Matrix A")
            printMatrix(a)
            b = inputMatrix()
            print("Matrix B")
            printMatrix(b)
            res = addition(a, b)
            if type(res) == str:
                print(res)
            else:
                print("Matrix A + B")
                printMatrix(res)

        elif choice == 2:
            a = inputMatrix()
            print("Matrix A")
            printMatrix(a)
            b = inputMatrix()
            print("Matrix B")
            printMatrix(b)
            res = subtraction(a, b)
            if type(res) == str:
                print(res)
            else:
                print("Matrix A - B")
                printMatrix(res)

        elif choice == 3:
            a = inputMatrix()
            print("Matrix A")
            printMatrix(a)
            b = inputMatrix()
            print("Matrix B")
            printMatrix(b)
            res = multiplication(a, b)
            if type(res) == str:
                print(res)
            else:
                print("Matrix A * B")
                printMatrix(res)

        elif choice == 4:
            a = inputMatrix()
            print("Matrix A")
            printMatrix(b)
            res = transpose(a)
            if type(res) == str:
                print(res)
            else:
                print("Matrix A`")
                printMatrix(res)
