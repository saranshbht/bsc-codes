preorder(nil, []):-!.
preorder(t(L, N, R), [N|List]):-
  preorder(L, LL),
  preorder(R, LR),
  append(LL, LR, List).

inorder(nil, []):-!.
inorder(t(L, N, R), List):-
  inorder(L, LL),
  inorder(R, LR),
  append(LL, [N|LR], List).

postorder(nil, []):-!.
postorder(t(L, N, R), List):-
  postorder(L, LL),
  postorder(R, LR),
  append(LL, LR, List2),
  append(List2, [N], List).
  
:- initialization(inorder(t(t(nil,2,nil),1, t(nil,3,nil)), L)).
% inorder(t(t(nil,2,nil),1, t(nil,3,nil)), L).
% preorder(t(t(nil,2,nil),1, t(nil,3,nil)), L).
% postorder(t(t(nil,2,nil),1, t(nil,3,nil)), L).
