% -----------SUBNETWORKS------------ %

initial(0,s).
initial(0,np).
initial(0,vp).

final(2,s).
final(2,np).
final(2,vp).

arc(0,1,np,s).
arc(1,2,vp,s).

arc(0,1,det,np).
arc(1,2,np,np).

arc(0,1,vp,vp).
arc(1,2,np,vp).

% ---------------------------------- %

word(np,broomstick).
word(np,harry).
word(det,a).
word(vp,flies).

% ---------------------------------- %

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
    initial(Node,s),                  
    recognize(s,Node,Symbols,[]).
