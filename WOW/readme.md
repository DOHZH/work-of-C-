# Intro

1. This program imitates battle program of War3. You need to process production and battle of 2 different camps, the red camp and the blue.
2. Each camp's headquarter can generate a new unit per hour. Generating new unit needs some health meta. If the camp don't have enough health meta, the production will be in production queue until the camp have enough health meta. For example, the camp will produce first new unit at 0:00, and the next unit will be produced at 1:00 if you have enough health meta, unless your camp will generate this new unit at 2:00, 3:00,...when your camp have enough health meta. 
3. Every soldier has different number which they get when they are produced.
4. The game has many cities, which will produce health meta per hour. All cities have different number. The soldier will get these health meta and put their flag in this city when get this city and don't meet enemy. 
5. If the soldier meet other soldier from different camp in the city, they will battle with each other. In the city which has odd number or red flag, red soldier will attack enemy at first and vice versa. If the enemy alive, he will attack back. After battle, the survivor will get health meta of this city. If they all alive, none of them can get health meta.
6. If 2 soldier get into enemy's headquarter, the camp of soldier will win.
7. Each meta has 4 types of soldier: iceman, wolf, ninja, lion, dragon. Each of them has unique ability.
   1. Iceman: loss 9 health every 2 step.
   2. wolf:  double attack, if kill the enemy
   3. ninja: can't attack back
   4. dragon: dragon will cheer after battle if he alive.
   5. lion: if lion die, the killer will get all health meta of lion.

# Structure of program

1. All input will be stored in [input.txt](https://github.com/DOHZH/work-of-C-/blob/master/WOW/input.txt) and the output result will be stored in [out put.txt](https://github.com/DOHZH/work-of-C-/blob/master/WOW/output.txt)

2. content of input.txt:

   1. this game will have n case and the number in first line is n
   2. other line will divided into n group every 3 line
   3. every 3 line:
      1. first: initial health of headquarter, the amount of cities, the max amount of soldier 
      2. second: red camp's  soldier's health
      3. third: blue camp's soldier's health 

3. Class city and its subclass: define cities and headquarters

   ![](https://github.com/DOHZH/work-of-C-/blob/master/pic/city_WOW.jpg?raw=true)

4. Class character and its subclass: define all type of soldier

   ![](https://github.com/DOHZH/work-of-C-/blob/master/pic/character_WOW.jpg?raw=true)

5. Class Clock: the timer

6. Class ReadText: read input.txt

7. Class global: define some enumeration class and function to help our code becoming cleaner