#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <cmath> 

#define MACHINE_PRECISION std::numeric_limits<double>::epsilon()

class Point {
private:
    double x, y, z;
    //static unsigned int cnt;

public:
    unsigned int id;

    Point(); // +
    ~Point(); // +
    Point(const Point&  p); // +
    Point(double x, double y, double z); // +

    double getX() const; // +
    double getY() const; // +
    double getZ() const; // +
    //static unsigned int getCnt(); // +
    void setX(double val); // +
    void setY(double val); // +
    void setZ(double val); // +

    Point& operator= (const Point& p); // +
    bool operator== (const Point& p) const; // +
    bool operator!= (const Point& p) const; // +
    bool operator>= (const Point& p) const; // +
    bool operator<= (const Point& p) const; // +
    bool operator> (const Point& p) const; // +
    bool operator< (const Point& p) const; // +
    friend std::ostream& operator<<(std::ostream& os, const Point& p); // +

    double dist2plane(std::vector<double>& plane_params); // +
    double dist2line(std::vector<double>& line_params, const Point& p);
    double dist2point(const Point& p); // +
    Point& proj2plane(std::vector<double>& plane_params);
    Point& proj2line(std::vector<double>& line_params, const Point& p);
    Point& line_move(const Point& p, double dist);

    friend Point& proj2plane(std::vector<double> &plane_params, const Point &p); // +
    friend double dist(const Point& p1, const Point& p2); // +

    void print() const; // +

};

