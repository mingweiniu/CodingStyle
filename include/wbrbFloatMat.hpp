void mat_to_file(const std::vector<std::vector<double>> & FloatMat, const std::string & SaveFile) {

	auto Mat{ FloatMat };

	using std::ofstream;
	using std::ifstream;
	using std::fstream;
	using std::ios;

	auto wid = static_cast<double>(1);

	ofstream fin(SaveFile, ios::binary);
	fin.write(reinterpret_cast<char*>(&wid), sizeof(double));
	for (auto & row : Mat) {
		for (auto & c : row) {
			fin.write(reinterpret_cast<char*>(&c), sizeof(double));
		}
	}
	fin.close();
}


std::vector<std::vector<double>> mat_from_file(const std::string & file)
{
	using std::vector;
	using std::ifstream;
	using std::ios;
	using std::cout;
	using std::move;

	ifstream fin(file, ios::binary);

	fin.seekg(0, ios::end);
	const size_t num_elements = fin.tellg() / sizeof(double);
	fin.seekg(0, ios::beg);

	vector<double> data(num_elements);
	fin.read(reinterpret_cast<char*>(&data[0]), num_elements * sizeof(double));
	fin.close();

	auto w = static_cast<int>(data[0]);
	auto h = static_cast<int>((data.size() - 1) / w);
	data.erase(data.begin(), data.begin() + 1);

	std::vector<std::vector<double>> output;
	output.reserve(h);
	for (auto r = 0; r < h; ++r) {
		std::vector<double> row;
		row.reserve(w);
		for (auto c = 0; c < w; ++c) {
			row.push_back(data[r * w + c]);
		}
		output.push_back(move(row));
	}

	cout << "from " << file << " read Mat(" << h << ", " << w << ")\n";
	return output;
}
