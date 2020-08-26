go:- write('Enter first number: '),
    read(X),
    write('Enter second number: '),
    read(Y),
    own_sum(X, Y, R),
    write('Sum of the numbers: '),
    write(R), nl.

own_sum(X, Y, R):- R is X + Y.

:- initialization(go).