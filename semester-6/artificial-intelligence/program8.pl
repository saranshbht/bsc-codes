go:- write('Enter N: '),
    read(N),
    towerOfHanoi(N, a, c, b).

towerOfHanoi(1, R1, R2, R3):- write('Move disk 1 from rod '),
                            write(R1),
                            write(' to rod '),
                            write(R2), nl.
towerOfHanoi(N, R1, R2, R3):-
                    K is N - 1,
                    towerOfHanoi(K, R1, R3, R2),
                    write('Move disk '),
                    write(N),
                    write(' from rod '),
                    write(R1),
                    write(' to rod '),
                    write(R2), nl,
                    towerOfHanoi(K, R3, R2, R1).
:- initialization(go).