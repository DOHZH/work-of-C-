# Intro

1. some GIS system is command line system
2. This program use command line to make a simple GIS system
3. execute this program and you can enter command to add/delete/set/judge geometry elements
4. use [input.txt](https://github.com/DOHZH/work-of-C-/blob/29f37aca8fbc5334d372476980818cdaafdd5864/GIS_SYSTEM/input.txt) to enter information and get results after a series of command in [output.txt](https://github.com/DOHZH/work-of-C-/blob/29f37aca8fbc5334d372476980818cdaafdd5864/GIS_SYSTEM/output.txt)

# Structure of program

## 1. Geometry

+ all geometry elements have name

### 1) Point: 

a point has abscissa (x) and ordinate (y)

1. add: add a new point in system
   1. add point [point_name] [coordinate]
2. Set: set point [point_name]
   1. set [coordinate\] :modify point coordinates
   2. move [coordinate] : move point. For example, "set point a1 move 1,-3" means: point a1's abscissa add 1 and ordinate minus 3
   3. name [new_name] : change point's name 
3. judge: 
   1. judge point [point_a1_name] equal [point_a2_name] : check whether a1 equals a2

### 2) Polyline

a line is made by a point set. Each point in the point set has a number 

1. add: add a new polyline
   1.  add polyline [name] [point_set]
2. Set: set polyline [name]
   1. set [point_number] [coordinate]:modify point coordinates
   2. move [point_number]\[coordinate] : move point. 
   3. del [point_number]: delete point
   4. set_length [length]: set line's real length
   5. name [new_name] : change polyline's name 

### 3) Ring

You can see a ring as a closed line

1. add: add a new ring
   1.  add ring [name] [point_set]
2. Set: set ring [name]
   1. set [point_number] [coordinate]:modify point coordinates
   2. move [point_number]\[coordinate] : move point. 
   3. del [point_number]: delete point
   4. set_length [length]: set ring's real perimeter
   5. set_area [area]: set ring's real area
   6. name [new_name] : change ring's name
3. judge: 
   1. judge ring [ring_name] cover [point_name]: check whether the point in the ring

### 4) Polygon

Polygon will have 2 section: an outer ring and an inner ring. The Polygon can only has an outer ring. The space surrounded by the outer and the inner is the polygon's area. Each polygon can only have one inner ring.

1. add: add a polygon with outer ring
   1. add polygon [name] outer [point_set]
2. Set: set polygon [name]
   1. inner [point_set]: add an inner ring in the polygon
   2. set outer [point_number] [coordinate]: modify point coordinates in outer ring
   3. set outer [point_number] [coordinate]: modify point coordinates in inner ring
   4. move outer [point_number]\[coordinate] : move point in outer ring.
   5. move inner [point_number]\[coordinate] : move point in outer ring.
   6. del outer [point_number]: delete point in the outer
   7. del inner [point_number]: delete point in the inner
   8. set_length [length]: set polygon's real perimeter
   9. set_area [area]: set polygon's real area
   10. name [new_name] : change polygon's name
3. judge: 
   1. judge polygon [polygon_name] cover [point_name]: check whether the point in the ring

## 2. Others

1. extra_geo_method: I put all the manipulation in this class, which can make code clean. Besides, the class can help us process errors.
2. divide_method: help us divide string in "input.txt"
2. string_to_float: change string into float