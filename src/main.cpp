
#include <iostream>
#include "audio/AudioAnalyzer.h"

constexpr const char* VERSION = "0.1.0";
constexpr const char* STATUS = "Development";

void printInfo()
{
	std::cout << "Audio Processing Engine\n";
	std::cout << "Version: " << VERSION << std::endl;
	std::cout << "Status: " << STATUS << std::endl;

}

int main()
{
	printInfo();
	AudioAnalyzer Analyzer;
	std::cout << Analyzer.getMessage() << "\n";
	return 0;
}

