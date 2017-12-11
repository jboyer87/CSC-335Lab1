# CSC-335 Lab 1

## Synopsis
The first lab covers several C++ data structures and algorithms exercises from the textbook, outlined below. 

## Project 1.1
A common punishment for school children is to write out the same sentence multiple times. Write a C++ stand - alone program that will write out the following sentence one hundred times : "I will always use object oriented design." Your program should number each of the sentences and it should "accidentally" make eight different random- looking typos at various points in the listing, so that it looks like a human typed it all by hand.

## Creativity 2.4
Design a class Line that implements a line, which is represented by the formula y = ax+b. Your class should store a and b as double member variables. Write a member function intersect(ℓ) that returns the x coordinate at which this line intersects line ℓ. If the two lines are parallel, then your function should throw an exception Parallel. Write a C++ program that creates a number of Line objects and tests each pair for intersection. Your program should print an appropriate error message for parallel lines.

## Project 3.2
Write a C++ program for a matrix class that can add and multiply arbitrary two-dimensional arrays of integers. Do this by overloading the addition ("+") and multiplication("*") operators.

## Project 3.3
Give C++ code for performing add(e) and remove(i) functions for game entries stored in an array a, as in class Scores in Section 3.1.1, except this time, don't maintain the game entries in order. Assume that we still need to keep n entries stored in indices 0 to n−1. Try to implement the add and remove functions without using any loops, so that the number of steps they perform does not depend on n.

## Project 4.1
Implement prefixAverages1 and prefixAverages2 from Section 4.2.5, and perform an experimental analysis of their running times. Visualize their running times as a function of the input size with a log-log chart.