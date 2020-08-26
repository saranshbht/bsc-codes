go:- write('Enter first number: '),
    read(X),
    write('Enter second number: '),
    read(Y),
    own_gcd(X, Y, G),
    write('GCD of the numbers: '),
    write(G), nl.

own_gcd(X, 0, X).
own_gcd(X, Y, G):- K is mod(X, Y),
                   own_gcd(Y, K, G).

:- initialization(go).