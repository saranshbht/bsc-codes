go:- write('Enter your date-of-birth'), nl,
     write('Enter Date: '),
     read(Date),
     write('Enter Month(january, february, etc.): '),
     read(Month),
     zodiac(bday(Date, Month), Sign),
     write('Your zodiac sign is: '),
     write(Sign), nl;
     write('Enter valid Date and Month').

zodiac(bday(Date, january), Sign):- Date > 31, !, fail; Date > 19, Sign = aquarius;
                                    Sign = capricorn.
zodiac(bday(Date, february), Sign):- Date > 29, !, fail; Date > 18, Sign = pisces; 
                                     Sign = aquarius.
zodiac(bday(Date, march), Sign):- Date > 31, !, fail; Date > 20, Sign = aries;
                                  Sign = pisces.
zodiac(bday(Date, april), Sign):- Date > 30, !, fail; Date > 19, Sign = taurus;
                                  Sign = aries.
zodiac(bday(Date, may), Sign):- Date > 31, !, fail; Date > 20, Sign = gemini;
                                Sign = taurus.
zodiac(bday(Date, june), Sign):- Date > 30, !, fail; Date > 20, Sign = cancer; 
                                 Sign = gemini.
zodiac(bday(Date, july), Sign):- Date > 31, !, fail; Date > 22, Sign = leo;
                                 Sign = cancer.
zodiac(bday(Date, august), Sign):- Date > 31, !, fail; Date > 22, Sign = virgo; 
                                   Sign = leo.
zodiac(bday(Date, september), Sign):- Date > 30, !, fail; Date > 22, Sign = libra;
                                      Sign = virgo.
zodiac(bday(Date, october), Sign):- Date > 31, !, fail; Date > 22, Sign = scorpio; 
                                    Sign = libra.
zodiac(bday(Date, november), Sign):- Date > 30, !, fail; Date > 21, Sign = sagittarius; 
                                     Sign = scorpio.
zodiac(bday(Date, december), Sign):- Date > 31, !, fail; Date > 21, Sign = capricorn;
                                     Sign = sagittarius.

:- initialization(go).