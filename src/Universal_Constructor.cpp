#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <type_traits>


class ToDo
{
public:
	template<class T,
		class = typename std::enable_if<std::is_convertible<T, std::string>::value, void>::type>
		explicit ToDo(T && input) :mData(std::forward<T>(input)) {}
	~ToDo()	{	}

private:
	std::string mData;

};


class Demo
{
public:
	template<typename T>
	Demo(T && input) :mData(std::forward<T>(input)) {}
	~Demo();
	const std::string getData();

private:
	std::string mData;
};


int main()
{

	using std::string;
	using std::move;
	using std::cout;

	string x1 = "x1 is not const";
	string x2 = "x2 is not const";
	const string y1 = "const y1";
	const string y2 = "const y2";

	Demo move_x(move(x1));
	Demo no_move_x(x2);

	Demo move_y(move(y1));
	Demo no_move_y(y2);

	cout << "x1 = " << x1 << '\n';
	cout << "x2 = " << x2 << '\n';
	cout << "y1 = " << y1 << '\n';
	cout << "y2 = " << y2 << '\n';

	cout << "move_x = " << move_x.getData() << '\n';
	cout << "no_move_x = " << no_move_x.getData() << '\n';
	cout << "move_y = " << move_y.getData() << '\n';
	cout << "no_move_y = " << no_move_y.getData() << '\n';


	cout << "end \n";
}


Demo::~Demo()
{
}

const std::string Demo::getData()
{
	return mData;
}
