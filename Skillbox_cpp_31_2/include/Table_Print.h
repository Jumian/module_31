#pragma once

#include <iostream>
#include <vector>

class CLIPrinter {
public:
	static void printVector(std::vector<int> vec, std::string delim,bool lineFeedOnEnd=true) {
		for (int i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << delim;
		}
		if (lineFeedOnEnd) endl();
	}
	static void endl() {
		std::cout << std::endl;
	}
};