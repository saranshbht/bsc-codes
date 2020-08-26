go:- write('Enter N: '),
    read(N),
    write('Enter P: '),
    read(P),
    own_power(N, P, R),
    write('N ^ P: '),
    write(R), nl.

own_power(0, P, 0).
own_power(X, 0, 1).
own_power(N, P, R):- P1 is P - 1,
                     own_power(N, P1, R1),
                     R is N * R1.

:- initialization(go).