//编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定
//流中读取数据，直至文件结束标识时停止。它将读取的数据打印在标准输出上。
//完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态

#include <iostream>
#include<string>
#include<cctype>
#include<vector>

using std::string;
using std::cin;
using std::cout; using std::endl;
using std::vector;
using std::begin;
using std::end;
using std::istream; using std::ostream;

istream &readis(istream& is) {
	int v;
	while (is >> v, !is.eof()) {
		if (is.bad()) {
			throw std::runtime_error("IO流错误");
		}
		if (is.fail()) {
			std::cerr << "数据错误，请重试" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	is.clear();
	return is;
}

int main()
{
	cout << "请输入一些整数， 按ctrl+Z结束" << endl;
	readis(cin);
	cout << "the end" << endl;
	return 0;
}