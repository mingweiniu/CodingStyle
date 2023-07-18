#ifndef CODING_STYLE_TYPE_HPP
#define CODING_STYLE_TYPE_HPP
// include guard named form file path

#include <string>

// namespace always lowercase
namespace coding {
	namespace style {
		
		// MACRO ALWAYS UPPERCASE
		enum class CodingStyleEnum
		{
			MACRO,
			ALWAYS,
			UPPERCASE
		};


		// Type Always Capital Case
		class Type
		{
		public:

			// Functor / Lambda are looked like the same naming rule
			Type(const std::string & input);
			~Type();

			// related to member always lowercase
			const std::string & get_demo_data() const;

			// variable always lowercase, avoid abbreviation
			int demo_variable;


		private:
			// c++ has standarder perfix "this->"
			std::string demo_data;

		};
	} // namespace style 
} // namespace coding 



#endif // !CODING_STYLE_TYPE_HPP
