
#include <iostream>
using namespace std;

bool isPalindorome(const string& input) {

	if (input.length() < 2) {
		return true;
	}

	if (input[0] == input[input.length() - 1]) {
		return isPalindorome(input.substr(1, input.length() - 2));
	}

	return false;
}

int digitSum(int input) {

	if (input == 0) {
		return 0;
	}

	return input % 10 + digitSum(input / 10);
}

int countways(int n) {

	if (n <= 1) {
		return n;
	}

	return countways(n - 1) + countways(n - 2);
}

int waysToClimb(int s) {
	return countways(s + 1);
}

int main() {

	//calling digitsum
	cout << digitSum(1234) << endl;

	//calling waysToClimb
	cout << waysToClimb(3) << endl;

	//calling isPalindorome
	if (isPalindorome("axxa")) {
		cout << "Yes, it is Palindorome!" << endl;
	}
	else {
		cout << "No, it is not Palndorome" << endl;
	}

	system("pause");

	return 0;
}

