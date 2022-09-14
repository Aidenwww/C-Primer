//��д����������һ��istream&����������ֵ����Ҳ��istream&���˺�����Ӹ���
//���ж�ȡ���ݣ�ֱ���ļ�������ʶʱֹͣ��������ȡ�����ݴ�ӡ�ڱ�׼����ϡ�
//�����Щ�������ڷ�����֮ǰ���������и�λ��ʹ�䴦����Ч״̬

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
			throw std::runtime_error("IO������");
		}
		if (is.fail()) {
			std::cerr << "���ݴ���������" << endl;
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
	cout << "������һЩ������ ��ctrl+Z����" << endl;
	readis(cin);
	cout << "the end" << endl;
	return 0;
}