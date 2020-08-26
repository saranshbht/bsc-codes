go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    write('Enter the index(N) at which the element is to be inserted(1-based indexing): '),
    read(N),
    write('Enter the element to be inserted: '),
    read(I),
    insert_nth(I, N, L, R),
    write('List after insertion: '),
    printList(R);
    write('Please specify a valid value of N.').

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

insert_nth(I, 1, L, R):- conc([I], L, R), !.
insert_nth(I, N, [X|Y], [X|Z]):- N1 is N - 1,
                                 insert_nth(I, N1, Y, Z).

:- initialization(go).