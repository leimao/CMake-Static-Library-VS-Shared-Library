#include "rectangle.hpp"

Rectangle::Rectangle(double w, double h) : Shape{}, m_width{w}, m_height{h} {}

Rectangle::Rectangle(double w, double h, std::string const& name)
    : Shape{name}, m_width{w}, m_height{h}
{
}

double Rectangle::area() const { return m_width * m_height; }