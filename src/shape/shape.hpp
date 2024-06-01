#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape() = default;
    Shape(std::string const& name);
    virtual double area() const = 0;
    std::string const& name() const;

protected:
    std::string m_name;
};

#endif // SHAPE_H