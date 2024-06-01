#include "shape.hpp"

Shape::Shape(std::string const& name) : m_name{name} {}

std::string const& Shape::name() const { return m_name; }