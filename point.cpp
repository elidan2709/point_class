#include "point.hpp"

Point::Point()
{
    this->x = this->y = this->z = 0;
    //++cnt;
    //this->id = cnt;
}

Point::Point(double vx, double vy, double vz)
{
    this->x = vx;
    this->y = vy;
    this->z = vz;
    //cnt++;
    //this->id = cnt;
}
Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    //this->id = ++cnt;
}

Point::~Point()
{
    //cnt--;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}
double Point::getZ() const
{
    return z;
}

//unsigned int Point::getCnt()
//{
//    return cnt;
//}

void Point::setX(double val)
{
    this->x = val;
}

void Point::setY(double val)
{
    this->y = val;
}

void Point::setZ(double val)
{
    this->z = val;
}

void Point::print() const
{
    std::cout << "point: (" << this->x << ", " 
        << this->y << ", " << this->z  << ")" << std::endl;
}

Point& Point::operator=(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;

    return *this;
}

bool Point::operator==(const Point &p) const
{
    return ((this->x - p.x) < MACHINE_PRECISION && (this->y - p.y) 
     < MACHINE_PRECISION && (this->z - p.z) < MACHINE_PRECISION);
}

bool Point::operator!=(const Point &p) const
{
        return !((this->x - p.x) < MACHINE_PRECISION && (this->y - p.y) 
     < MACHINE_PRECISION && (this->z - p.z) < MACHINE_PRECISION);
}

bool Point::operator>=(const Point &p) const
{
    Point zero;
    zero.setX(0);
    zero.setY(0);
    zero.setZ(0);

    return (dist(*this, zero) - dist(p, zero)) >= 0;
}

bool Point::operator<=(const Point &p) const
{
    Point zero;
    zero.setX(0);
    zero.setY(0);
    zero.setZ(0);

    return (dist(*this, zero) - dist(p, zero)) <= 0;
}

bool Point::operator>(const Point &p) const
{
    Point zero;
    zero.setX(0);
    zero.setY(0);
    zero.setZ(0);

    return (dist(*this, zero) - dist(p, zero)) > 0;
}

bool Point::operator<(const Point &p) const
{
    Point zero;
    zero.setX(0);
    zero.setY(0);
    zero.setZ(0);

    return (dist(*this, zero) - dist(p, zero)) < 0;
}

std::ostream& operator<<(std::ostream &os, const Point &p)
{
    os << '(' << std::to_string(p.getX()) <<  ' ' << std::to_string(p.getY()) 
        << ' ' << std::to_string(p.getZ()) << ')';
    return os;
}

double Point::dist2plane(std::vector<double> &plane_params)
{
    //TODO: exception                                           here \|/ and division by zero
    plane_params.size() == 4 ? void() : (std::cerr << "wrong plane_params quantity" << std::endl, void());
    
    return std::abs(plane_params[0] * this->x + plane_params[1] * this->y + 
        plane_params[2] * this->z + plane_params[3]) / sqrt(plane_params[0] * plane_params[0] 
            + plane_params[1] * plane_params[1] + plane_params[2] * plane_params[2]);
}

double Point::dist2point(const Point &p)
{
    return std::sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * 
        (this->y - p.y) + (this->z - p.z) * (this->z - p.z));
}

double dist(const Point &p1, const Point &p2)
{
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * 
        (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

Point& Point::proj2plane(std::vector<double> &plane_params)
{    
    double t = (-plane_params[0] * this->x -plane_params[1] * this->y 
        -plane_params[2] * this->z - plane_params[3]) / (plane_params[0] * plane_params[0] 
            + plane_params[1] * plane_params[1] + plane_params[2] * plane_params[2]);
    
    this->x += t * plane_params[0];
    this->y += t * plane_params[1];
    this->z += t * plane_params[2];
    
    return *this;
}

Point& proj2plane(std::vector<double> &plane_params, Point &p)
{    
    double t = (-plane_params[0] * p.getX() -plane_params[1] * p.getY() 
        -plane_params[2] * p.getZ() - plane_params[3]) / (plane_params[0] * plane_params[0] 
            + plane_params[1] * plane_params[1] + plane_params[2] * plane_params[2]);
    
    
    p.setX(p.getX() + t * plane_params[0]);
    p.setY(p.getY() + t * plane_params[1]);
    p.setX(p.getZ() + t * plane_params[2]);
    
    return p;
}
double Point::dist2line(std::vector<double> &line_params, const Point &p)
{
    return 0.0;
}

Point& Point::proj2line(std::vector<double> &line_params, const Point &p)
{
    // TODO: realization
    return *this;
}

Point &Point::line_move(const Point &p, double dist)
{
    // TODO: realization
    return *this;
}