#include "Word.h"
#include <iostream>

int main() {
	while(std::cin.good()) {
		Word w{};
		std::cin >> w;
		std::cout << w << "\n";
	}
}
