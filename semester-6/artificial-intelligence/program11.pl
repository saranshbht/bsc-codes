go:- write('Enter List 1(-1 to specify end)'),
    nl,
    createList(L1),
    write('List 1: '),
    printList(L1),
    nl,
    write('Enter List 2(-1 to specify end)'),
    nl,
    createList(L2),
    write('List 2: '),
    printList(L2),
    nl,
    conc(L1, L2, L3),
    write('Concatenated List: '),
    printList(L3).

enterElement(X):- write('Enter element: '),
                  read(X).

createList(L):- enterElement(X),
                createListHelper(X, L).
createListHelper(-1, []):- !.
createListHelper(X, [X|Y]):- enterElement(X1),
                       createListHelper(X1, Y).

printList([]):- !.
printList([X|Y]):-  write(X),
                    write(' '),
                    printList(Y).
conc([], L2, L2).
conc([X|Y], L2, [X|Z]):- conc(Y, L2, Z).

:- initialization(go).