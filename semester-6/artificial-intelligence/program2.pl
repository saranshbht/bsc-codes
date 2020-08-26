go:- write('Enter first number: '),
    read(X),
    write('Enter second number: '),
    read(Y),
    own_max(X, Y, M),
    write('Maximum of the numbers: '),
    write(M).

own_max(X, Y, M):- X > Y, M is X;
                M is Y.

:- initialization(go).