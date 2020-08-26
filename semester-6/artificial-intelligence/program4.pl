go:- write('Enter N: '),
    read(N),
    generate_fib(N, T),
    write('Nth Fibonacci number: '),
    write(T), nl.

generate_fib(1, 1).
generate_fib(2, 1).
generate_fib(N, T):- A is N - 1,
                     B is N - 2,
                     generate_fib(A, C),
                     generate_fib(B, D),
                     T is C + D.
:- initialization(go).