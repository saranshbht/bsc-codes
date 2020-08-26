go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    write('Length of list: '),
    length_of(L, N),
    write(N).

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
                    
length_of(L, N):- length_of(L, 0, N).
length_of([], A, A).
length_of([X|Y], A, N):- A1 is A + 1,
                         length_of(Y, A1, N).

:- initialization(go).


