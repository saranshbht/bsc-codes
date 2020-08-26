go:- write('Enter a number: '),
    read(X),
    sumOfDigits(X, S),
    write('Sum of digits of the number: '),
    write(S), nl.

sumOfDigits(0, 0).
sumOfDigits(X, S):- X < 0,
                    XP is -X,
                    sumOfDigits(XP, S);
                    X1 is X // 10,
                    K is mod(X, 10),
                    sumOfDigits(X1, R),
                    S is K + R.

:- initialization(go).