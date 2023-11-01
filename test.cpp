#include "point.hpp"

int main(void){
// TODO: asserts

Point p_z;
p_z.setX(0.0);
p_z.setY(0.0);
p_z.setZ(0.0);

const Point z = p_z;

Point p;
p.setX(1);
p.setY(-3);
p.setZ(2);
Point p2(p);
Point p3 = p;
Point p4 = p_z;

// testing
std::cout << "------set-get test------" << std::endl;
std::cout << p.getX() << '\t' << p.getY() << '\t' << p.getZ() << std::endl;
std::cout << p2.getX() << '\t' << p.getY() << '\t' << p2.getZ() << std::endl;
std::cout << p3.getX() << '\t' << p.getY() << '\t' << p3.getZ() << std::endl;
std::cout << "------machine precision------" << std::endl;
std::cout << MACHINE_PRECISION << std::endl;
std::cout << std::endl;
std::cout << "------==, !=, = and copy constructor test------" << std::endl;
std::cout << (p == p2) << ' ' << (p != p3) << (z == p_z) << std::endl;
std::cout << std::endl;
std::cout << "------ostream& << test------" << std::endl;
std::cout << p_z << std::endl;
std::cout << p4 << std::endl;
std::cout << std::endl;
std::cout << "------print() test------" << std::endl;
p.print();
std::cout << std::endl;
std::cout << "------<=, >=, >, < test------" << std::endl;
std::cout << (p > p2) << std::endl;
std::cout << (p < p2) << std::endl;
std::cout << (z >= p_z) << std::endl;
std::cout << (z <= p_z) << std::endl;
std::cout << (z < p_z) << std::endl;
std::cout << (z > p_z) << std::endl;
std::cout << "------dist and proj test------" << std::endl;
std::cout << p_z.dist2point(p) << std::endl;
std::cout << dist(p_z, z) << ' ' <<  dist(p, p_z) << std::endl;
std::vector<double> params = {2, 5, -3, -19};
std::cout << p.dist2plane(params) << std::endl;
std::cout << p.proj2plane(params) << std::endl;
std::vector<Point> point_arr;
}