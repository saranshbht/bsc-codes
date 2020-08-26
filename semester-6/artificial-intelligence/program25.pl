initial(1, s).

initial(1, pp).

initial(1, np).


final(5, s).
final(6, s).

final(3, np).
final(4, np).

final(3, pp).


arc(1, 2, np, s).
arc(2, 5, v, s).
arc(5, 6, np, s).
arc(6, 6, pp, s).
arc(1, 3, aux, s).
arc(3, 4, np, s).
arc(4, 5, v, s).

arc(1, 2, det, np).
arc(2, 2, adj, np).
arc(2, 4, n, np).
arc(4, 4, pp, np).
arc(1, 3, pr, np).

arc(1, 2, prep, pp).
arc(2, 3, np, pp).


word(det, the).
word(det, a).
word(adj, big).
word(n, tree).
word(v, shades).
word(adj, old).
word(n, house).
word(prep, by).
word(n, stream).
word(n, boy).
word(v, drives).
word(n, car).


recognize(Subnet,Node,X,X) :-
    final(Node,Subnet).
recognize(Subnet,Node_1,X,Z) :-
    arc(Node_1,Node_2,Label,Subnet),
    traverse(Label,X,Y),
    recognize(Subnet,Node_2,Y,Z).


traverse(Label,[Symbol|Symbols],Symbols) :-   
    word(Label,Symbol).
traverse(Subnet,String,Rest) :-
    initial(Node,Subnet),
    recognize(Subnet,Node,String,Rest).


test(Symbols) :-                  
    initial(Node, S),                  
    recognize(S,Node,Symbols,[]).