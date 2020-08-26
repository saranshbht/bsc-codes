car(car1, black, 450000).
car(car2, silver, 300000).
car(car3, white, 400000).
car(car4, black, 450000).
getcar(Color, Cost_Less_Than):- car(Name, Color, Cost), !,
                                Cost < Cost_Less_Than,
                                write(Name).