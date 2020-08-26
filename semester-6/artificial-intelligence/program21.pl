go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    write('Enter the index(N) of the element to be deleted(1-based indexing): '),
    read(N),
    delete_nth(N, L, R),
    write('List after deletion: '),
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

delete_nth(1, [X|Y], Y):- !.
delete_nth(N, [X|Y], [X|Z]):- N1 is N - 1,
                              delete_nth(N1, Y, Z).

:- initialization(go).