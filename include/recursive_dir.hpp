std::vector<std::string> recursive_dir(std::string directory_path)
{
	using std::cout;
	using std::vector;
	using std::string;
	using std::move;
	using std::deque;

	using namespace boost::filesystem;
	using dir_iter = directory_iterator;

	vector<string> output;
	deque<string> que{ directory_path };

	while (!que.empty()) {
		auto& head = que.front();

		if (!is_directory(path(head)))
		{
			std::cout << '\t' << head << '\n';
			output.push_back(head);
		}
		else
		{
			path dir_path(head);
			for (auto& entry : boost::make_iterator_range(dir_iter(dir_path), dir_iter())) {
				auto temp_path = entry.path();
				auto file_name = temp_path.string();

				que.push_back(move(file_name));
			}

		}
		que.erase(que.begin());
	}

	return output;
}
