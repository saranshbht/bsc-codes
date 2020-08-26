go:- write('Enter first number: '),
    read(X),
    write('Enter second number: '),
    read(Y),
    multiply(X, Y, R),
    write('Result of multiplication of the numbers: '),
    write(R), nl.

multiplyHelper(X, 0, 0).
multiplyHelper(X, Y, R):- Y1 is Y - 1,
                          multiply(X, Y1, R1),
                          R is R1 + X.
multiply(X, Y, R):- Y < 0,
                    Y1 is -1 * Y,
                    multiplyHelper(X, Y1, R1),
                    R is -1 * R1;
                    multiplyHelper(X, Y, R).

:- initialization(go).