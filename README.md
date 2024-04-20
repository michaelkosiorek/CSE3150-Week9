# CSE3150-Week9

Compile unit tests w/: <br>
```g++ unit_test_triangle.cpp triangle.cpp -o unit_tests``` <br>
and test your own triangle using the main file: <br>
```g++ tri_main.cpp triangle.cpp -o main```.

* Regarding what was requested in the assignment pdf:
    * The constructors have finally gotten more advanced than just initializing the basic fields of the struct.
  This is my first time seeing how these constructors may need to call functions and initialize things that
  are not already known by the user of the class. Interesting, good assignment.
    * The setters getters are implemented.
    * The Triangle struct and Point3d have their own ostream operators.
