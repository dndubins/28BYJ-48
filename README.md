# Library for 28BYJ-48 stepper motor, connected to a ULN2003 stepper motor driver

This is a simple (blocking) stepper motor library for the 28BYJ-48 5V or 12V stepper motor, driven by the ULN2003 controller.

The code in this library was loosely adapted from "Attempted fun with engineering": http://engyfun.blogspot.ca/2015/02/here-is-source-code-for-our-28byj48.html 
Posted by Unknown on Saturday, 7 February 2015.

The original library had the user input the delay to control the speed. This version has the user input rpm as a float number (so less than 1 rpm is possible), and converts that to the appropriate delay in the library.
