// self header first
#include <coding/style/Type.hpp>

// C standard libraries
#include <cmath>

// C++ standard libraries
#include <string>
#include <vector>

// boost library

// Other libraries

// Your project's headers



coding::style::Type::Type(const std::string & input):
	demo_data(input)
{	
	// prefer initialize
}

coding::style::Type::~Type()
{
}

const std::string & coding::style::Type::get_demo_data() const
{
	return this->demo_data;
}
