#ifndef CODING_STYLE_FUNCTION_HPP
#define CODING_STYLE_FUNCTION_HPP


// perfer comment of "//"

namespace coding {
	namespace style {
	
		// Prefer Trailing Return Type
		template<typename T>
		auto Function() -> T{

			T output;

			return output;
		}

	
	} // namespace style 
} // namespace coding 



#endif // !CODING_STYLE_FUNCTION_HPP