go:- write('Enter List(-1 to specify end)'),
    nl,
    createList(L),
    write('List: '),
    printList(L),
    nl,
    write('Enter the index(N) of the element to be found(1-based indexing): '),
    read(N),
    nth_element(N, L, X),
    write('The Nth element of the list is: '),
    write(X);
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
nth_element(1, [H|_], H):- !.
nth_element(N, [_|T], X):- N1 is N - 1,
                           nth_element(N1, T, X).
:- initialization(go).