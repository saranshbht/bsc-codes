go:- write('Enter N: '),
    read(N),
    own_factorial(N, F),
    write('Factorial of the number: '),
    write(F), nl.

own_factorial(0, 1).
own_factorial(N, F):- K is N - 1,
                      own_factorial(K, R),
                      F is N * R.
:- initialization(go).