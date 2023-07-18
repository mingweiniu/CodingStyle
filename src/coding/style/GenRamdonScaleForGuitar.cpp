#include <cstdlib>
#include <cmath>
#include <ctime>


#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <iterator>
#include <chrono>

std::string GenRamdonScaleForGuitar() 
{
	using std::chrono::system_clock;
	using std::cout;
	using std::time_t;
	using std::srand;
	using std::ostringstream;

	using std::string;
	using std::vector;

	auto current = system_clock::now();
	time_t now_c = system_clock::to_time_t(current);

	// use current time as seed for random generator
	srand(now_c); 

	vector<string> roots = { 
		"C",
		"D♭",
		"D",
		"E♭",
		"E",
		"F",
		"G♭",
		"G",
		"A♭",
		"A",
		"B♭",
		"B"
	};

	vector<string> scales = { 
		"Harmonic minor",
		"Melodic minor",
		"Blue",
		"Whole tone",
		"Pentatonic",
		"Ionian",
		"Dorian",
		"Phrygian",
		"Lydian",
		"Mixolydian",
		"Aeolian",
		"Locrian"
	};

	int random1 = std::rand() % 10 + 1;
	int random2 = std::rand() % scales.size();
	int random3 = std::rand() % roots.size();



	ostringstream oss;

	oss << random1 << " fretting with " << scales[random2] << " scale on " << roots[random3] << '\n';


	return oss.str();
}

/*
int main() 
{
	std::cout << GenRamdonScaleForGuitar();
}
*/
