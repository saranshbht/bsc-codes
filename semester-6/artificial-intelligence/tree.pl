go:- preorder(tree(1, tree(2, tree(4, nil, nil), tree(5, nil, nil)), tree(3, tree(6, nil, nil), tree(7, nil, nil))), List), printList(List), nl.

inorder(nil).
inorder(tree(X, L, R)):- 
    inorder(L),
    write(X), write(' '),
    inorder(R).

postorder(nil).
postorder(tree(X, L, R)):- 
    postorder(L),
    postorder(R),
    write(X), write(' ').

preorder(nil, []):- !.
preorder(tree(X, L, R), [X|List]):- 
    preorder(L, LL),
    preorder(R, RR),
    append(LL, RR, List).
printList([]).
printList([X|Y]):-  write(X),
                    write(' '),
                    printList(Y).


:- initialization(go).