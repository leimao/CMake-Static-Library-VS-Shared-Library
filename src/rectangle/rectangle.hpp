#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h);
    Rectangle(double w, double h, std::string const& name);
    double area() const override;

private:
    double m_width;
    double m_height;
};

#endif // RECTANGLE_H