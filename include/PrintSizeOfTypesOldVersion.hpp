#include <iostream>
#include <boost/type_index.hpp>

template<typename ...Ts>
void PrintSizeOfTypes(Ts... next);

template<typename T, typename ...Us>
void PrintSizeOfTypes(T print, Us... next)
{
		std::cout << boost::typeindex::type_id<T>().pretty_name() << " is sizeof " << sizeof(T) << '\n';
		PrintSizeOfTypes(next...);
}
template<>
void PrintSizeOfTypes()
{
}


void TestPrintSizeOfTypes()
{
	PrintSizeOfTypes(
		static_cast<char*>("testing size"),
		static_cast<short>(5.5),
		static_cast<int>(5.5),
		static_cast<long>(5.5),
		static_cast<long long>(5.5),
		static_cast<float>(5.5),
		static_cast<double>(5.5),
		static_cast<unsigned short>(5.5),
		static_cast<unsigned int>(5.5),
		static_cast<unsigned long long>(5.5)
	);
}
