#include <iostream>
#include <boost/mpl/list.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/type_index.hpp>

template<typename ...Ts>
class PrintSizeOfTypes
{
public:
	struct PrintTypeSize {
		template<typename T>
		void operator()(T t) {
			using std::cout;
			using boost::typeindex::type_id_with_cvr;
			cout << "Size of " << type_id_with_cvr<T>().pretty_name() << ": " << sizeof(T) << " bytes\n";
		}
	};

	PrintSizeOfTypes() { boost::mpl::for_each<boost::mpl::list<Ts...>>(PrintTypeSize()); }
	~PrintSizeOfTypes() {}
};

void TestPrintSizeOfTypes() {
	PrintSizeOfTypes<char, char*, int, int*, float, float*, double, double*>();
}
