#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

int main() {
	int option;
	std::cout << "Enter 1 to encode a sus code." << std::endl;
	std::cout << "Enter 2 to decode a sus code." << std::endl;
	std::cin >> option;
	if (option == 1) {
		std::string input;
		std::string input1;
		std::cout << "Enter the text you would like to encode." << std::endl;
		getline(std::cin >> std::ws, input);
		for (int i = 0; i < input.length(); i++) {
			int ascii = input[i] + 0;
			ascii += 69;
			input1 = input1 + "sus" + std::to_string(ascii);
		}
		std::cout << input1 << std::endl;
	}
	else if (option == 2) {
		std::string input;
		std::string output;
		std::string currentascii;
		std::vector<int> asciicodes;
		std::cout << "Enter the sus code you would like to decode." << std::endl;
		std::cin >> input;
		bool badcode = false;
		if (isdigit(input[1])) {
			badcode = true;
		}
		for (int i = 0; i < input.length(); i++) {
			if (isdigit(input[i]) && i < input.length() - 1) {
				currentascii += input[i];
			}
			else if (isalpha(input[i]) && input[i] != 's') {
				if (input[i] != 'u') {
					badcode = true;
				}
			}
			else if (isdigit(input[i]) && i == input.length() - 1) {
				currentascii += input[i];
				asciicodes.push_back(stoi(currentascii));
				currentascii = "";
			}
			else if (currentascii.length() != 0) {
				asciicodes.push_back(stoi(currentascii));
				currentascii = "";
			}
		}
		if (badcode == false) {
			for (int i = 0; i < asciicodes.size(); i++) {
				output = output + char(asciicodes[i] - 69);
			}
			std::cout << output << std::endl;
		}
		else {
			std::cout << "Please input a valid sus code next time." << std::endl;
		}
	}
	else if (option != 1 && option != 2) {
		std::cout << "Please type in a valid input next time.";
	}

	system("pause");
	return 0;
}