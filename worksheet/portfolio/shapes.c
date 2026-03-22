#include <stdbool.h>
#include <math.h>
#include "shapes.h"

#define EPS 1e-6   // small value for float comparison


// --- making structs ---

Point makePoint(float x, float y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

Line makeLine(Point p1, Point p2) {
    Line l;

    l.p[0] = p1;
    l.p[1] = p2;

    return l;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle t;

    t.p[0] = p1;
    t.p[1] = p2;
    t.p[2] = p3;

    return t;
}


// --- calculations ---

float lineLength(Line l) {
    float dx, dy;

    dx = l.p[1].x - l.p[0].x;
    dy = l.p[1].y - l.p[0].y;

    return sqrt(dx*dx + dy*dy);
}


float triangleArea(Triangle t) {
    float x1 = t.p[0].x;
    float y1 = t.p[0].y;
    float x2 = t.p[1].x;
    float y2 = t.p[1].y;
    float x3 = t.p[2].x;
    float y3 = t.p[2].y;

    float area;

    area = (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;

    if (area < 0) {
        area = -area;   // make positive
    }

    return area;
}


// --- comparisons ---

bool samePoint(Point p1, Point p2) {

    if (fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS) {
        return true;
    }

    return false;
}


bool pointInLine(Point p, Line l) {

    if (samePoint(p, l.p[0])) {
        return true;
    }

    if (samePoint(p, l.p[1])) {
        return true;
    }

    return false;
}


bool pointInTriangle(Point p, Triangle t) {

    if (samePoint(p, t.p[0])) return true;
    if (samePoint(p, t.p[1])) return true;
    if (samePoint(p, t.p[2])) return true;

    return false;
}