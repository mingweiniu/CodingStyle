#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

std::vector<std::string> SpiltStringStream(std::string input)
{
	using std::istringstream;
	using std::istream_iterator;
	using std::string;
	using std::vector;

	istringstream buffer(input);
	istream_iterator<string> begin(buffer), end;

	return vector<string>(begin, end);
}

void TestSpiltStringStream()
{
	using std::istringstream;
	using std::vector;
	using std::string;
	using std::getline;
	using std::cout;

	istringstream test_stream(
		"test\n"
		"5 22 43924 432 1111\n"
	);

	vector<vector<string>> inputs;
	string one_line;
	while (getline(test_stream, one_line))
	{
		inputs.push_back(SpiltStringStream(one_line));
	}


	for (int i = 0; i < inputs.size(); ++i)
	{
		for (int j = 0; j < inputs[i].size(); ++j) 
		{
			cout << inputs[i][j];

			if (i < inputs.size() - 1)
			{
				cout << '\t';
			}
		}		


		if (i < inputs.size() - 1)
		{
			cout << '\n';
		}
	}
}
