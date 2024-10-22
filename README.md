# CPP Module 02 - Fixed Point Numbers & BSP

This repository contains my implementation of the CPP Module 02 exercises from the 42 school curriculum.

## Overview
This module focuses on operator overloading and fixed-point arithmetic in C++. Through these exercises, I implemented a fixed-point number class and used it to create a point-in-triangle checker using Binary Space Partitioning (BSP).

## Implementation Details

### Fixed Point Number Class
- Implemented a fixed-point number system using a 32-bit integer with 8 bits for the fractional part
- Overloaded arithmetic operators (+, -, *, /) with proper rounding
- Implemented comparison operators (<, >, <=, >=, ==, !=)
- Added conversion functions between fixed-point and floating-point numbers

Key design choices:
```cpp
class Fixed {
private:
    int               _rawValue;
    static const int  _FRACTIONAL_BITS = 8;
};
```

### Point Class
- Uses two Fixed numbers to represent x and y coordinates
- Implements getters for coordinates
- Follows Orthodox Canonical Form

### BSP (Binary Space Partitioning)
- Uses the area method to determine if a point lies inside a triangle
- Handles edge cases (points on vertices or edges)
- Ensures accurate results with fixed-point arithmetic

## Building and Testing

### Requirements
- C++ compiler with C++98 support
- Make

### Build
```bash
make        # Build the exercise
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Rebuild all
make run     # Build and run the test
```

### Running Tests
Each exercise comes with a main program demonstrating its functionality:
```bash
./fixed      # Tests fixed-point number class
./bsp        # Tests point-in-triangle checking
```

## Key Learnings
1. Understanding fixed-point arithmetic and its implementation
2. Proper operator overloading in C++
3. Working with Orthodox Canonical Form
4. Implementing geometric algorithms with fixed-point precision
5. Handling edge cases in floating-point alternatives

## Exercise Structure

### ex00: Orthodox Canonical Fixed Point Class
- Basic fixed-point number implementation
- Orthodox Canonical Form compliance

### ex01: Advanced Fixed Point Operations
- Conversion constructors
- Basic arithmetic operations
- Comparison operations

### ex02: Static Member Functions
- Min/max functionality
- Advanced operator overloading

### ex03: BSP Implementation
- Point class implementation
- Triangle point-inclusion algorithm
- Geometric calculations using fixed-point arithmetic

## Notes
- All classes follow Orthodox Canonical Form
- No memory leaks in any implementation
- Compliant with C++98 standard
- Passes all 42 tests

## Resources Used
- [Fixed-point arithmetic explained](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- [Point in Triangle test](https://en.wikipedia.org/wiki/Point_in_polygon)
- C++ Reference for operator overloading
