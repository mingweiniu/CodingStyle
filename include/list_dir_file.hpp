

#include <iostream>
#include <utility>
#include <vector>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>


std::vector<std::string> list_dir(std::string directory_path)
{
	using std::cout;
	using std::vector;
	using std::string;
	using std::move;

	using namespace boost::filesystem;
	using dir_iter = directory_iterator;

	vector<string> output;

	path dir(directory_path);
	if (!is_directory(dir)) {
		cout << directory_path << " is not a directory path";
		std::exit(EXIT_SUCCESS);
	}
	else {
		path dir_path(directory_path);
		for (auto& entry : boost::make_iterator_range(dir_iter(dir_path), dir_iter())) {
			auto temp_path = entry.path();
			auto file_name = temp_path.string();
			std::cout << '\t' << file_name << '\n';
			output.push_back(move(file_name));
		}
	}
	return output;
}
