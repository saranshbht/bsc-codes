my_menu:-
  nl, nl, 
  write('1. Factorial'),nl,
  write('2. Fibonacchi'),nl,
  write('0. Exit'),nl,
  write('Enter Choice ... '),
  read(Option),
  my_menu(Option).

q1:- write('Task 1 Performed').
q2:- write('Task 2 Performed').
exit:- write('Exiting...').

my_menu(Option):-
  nl,
  write('You choose '),
  write(Option),nl,
  fail.

my_menu(1):- 
  q1, 
  my_menu.
my_menu(2):- 
  q2,
  my_menu.
my_menu(0):- exit.
my_menu(_):-
  write('Invalid option'),
  my_menu.



:- initialization(my_menu).
