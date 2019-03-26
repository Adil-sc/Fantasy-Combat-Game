# Fantasy Combat Game

A fantasy combat game in which two players can select a roster of characters and battle each other. 

The game plays as follows:
Each combat between 2 characters ends when one of the characters die.
Each round consists of two attacks, one for each character. For each attack, attacker and defender both generate dice rolls. The type and number of dice is listed above in the table.
The actual damage inflicted from the attacker onto the defender is calculated as follows:

Damage = attacker’s roll – defender’s roll – defender’s armor

Then the value of that damage is subtracted from the defender’s strength points.

## Installation and Usage
Compile the program with this command:
```
make FinalProject
```
Run with the following command:
```unix
./FinalProject
```

## Built With
c++

