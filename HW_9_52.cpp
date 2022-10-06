#include<iostream>
#include<stack>
#include<string>
#include<cctype>

using std::string;
using std::stack;
using std::cin; using std::cout;
using std::endl;

void trim(string& s)
{
	string::size_type index = 0;
	if (!s.empty()) {
		while ((index = s.find(' ', index)) != string::npos) {
			s.erase(index, 1);
		}
	}
}

double calculate(const string& s)
{
	string numbers(".0123456789");
	auto pos = s.find_first_not_of(numbers);
	string left = s.substr(0, pos); string right = s.substr(pos + 1);
	switch (s[pos]) {
		case '+':
			if (right.find_first_not_of(numbers) == string::npos) {
				return std::stod(left) + std::stod(right);
			}
			else {
				return std::stod(left) + calculate(right);
			}
			break;
		case '-':
			if (right.find_first_not_of(numbers) == string::npos) {
				return std::stod(left) - std::stod(right);
			}
			else {
				return std::stod(left) - calculate(right);
			}
			break;
		case '*':
			if (right.find_first_not_of(numbers) == string::npos) {
				return std::stod(left) * std::stod(right);
			}
			else {
				return std::stod(left) * calculate(right);
			}
			break;
		case '/':
			if (right.find_first_not_of(numbers) == string::npos) {
				return std::stod(left) / std::stod(right);
			}
			else {
				return std::stod(left) / calculate(right);
			}
			break;
	}
}

double calculate_exp(string& exp) 
{
	stack<char> result;
	string exp_simplified;

	trim(exp);

	for (auto c : exp) {
		if (c != ')') {
			result.push(c);
		}
		else {
			string temp;
			auto i = temp.begin();
			while (result.top() != '(') {
				i = temp.insert(i, 1, result.top());
				result.pop();
			}
			result.pop();

			double simp = calculate(temp);
			for (auto c_ : std::to_string(simp)) {
				result.push(c_);
			}
		}
	}

	auto item = exp_simplified.begin();
	while (!result.empty()) {
		item = exp_simplified.insert(item, 1, result.top());
		result.pop();
	}

	return calculate(exp_simplified);
}

int main()
{
	string exp = "(( 25.2 + 3.16 - 6.72 ) + (5.28 - 3.14)) / 2";
	
	cout << exp << " = " << calculate_exp(exp) << endl;

}