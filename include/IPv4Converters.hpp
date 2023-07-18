#include <string>

unsigned long IPv4toUnsignedLong(const std::string &input) {

	auto ipv4{ input + '.'};

	char p[4] = {};	
	for (int i = 0; i < 4; ++i) {
		int n = ipv4.find('.');
		std::string temp(ipv4.begin(), ipv4.begin() + n);
		ipv4.erase(ipv4.begin(), ipv4.begin() + n + 1);
		p[3 - i] = atoi(temp.data());
	}
	return *(reinterpret_cast<unsigned long*>(p));

}

std::string UnsignedLongtoIPv4(const unsigned long &input) {

	std::string output{};

	const char* p = reinterpret_cast<const char* >(&input);
	for (int i = 0; i < 4; ++i) {
		auto t = static_cast<int>(p[3 - i]);

		output += std::to_string(t);
		output += '.';
	}

	output.pop_back();

	return output;
}
