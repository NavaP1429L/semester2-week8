#include <stdio.h>
#include <stdbool.h>

#include "shapes.h"

int main(void) {

    // --- points ---
    Point p1 = makePoint(0.0, 0.0);
    Point p2 = makePoint(3.0, 4.0);
    Point p3 = makePoint(0.0, 4.0);
    Point p4 = makePoint(0.0, 0.0); // same as p1

    // --- line ---
    Line l = makeLine(p1, p2);

    // --- triangle ---
    Triangle t = makeTriangle(p1, p2, p3);


    // --- test line length ---
    float len = lineLength(l);
    printf("Line length: %f\n", len);


    // --- test triangle area ---
    float area = triangleArea(t);
    printf("Triangle area: %f\n", area);


    // --- test samePoint ---
    if (samePoint(p1, p4)) {
        printf("p1 and p4 are the same\n");
    } else {
        printf("p1 and p4 are different\n");
    }


    // --- test pointInLine ---
    if (pointInLine(p1, l)) {
        printf("p1 is in the line\n");
    } else {
        printf("p1 is not in the line\n");
    }


    // --- test pointInTriangle ---
    if (pointInTriangle(p2, t)) {
        printf("p2 is in the triangle\n");
    } else {
        printf("p2 is not in the triangle\n");
    }


    // extra random check
    Point p5 = makePoint(1.0, 1.0);

    if (pointInTriangle(p5, t)) {
        printf("p5 is in triangle (vertex)\n");
    } else {
        printf("p5 is NOT a triangle vertex\n");
    }

    return 0;
}