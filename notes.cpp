#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<vector>
// #include "Sales_item.h"

using std::string;
using std::cin;
using std::cout; using std::endl;
using std::vector;
using std::begin;
using std::end;

//TODO: 缺少头文件 Sales_Item，仅作为笔记翻阅

extern const int bufsize = 512;

int main()
{
	//?############################################################################################ while控制流
	//?while循环
	//int sum = 0, val = 50;
	//while (val <= 100) {
	//	sum += val;
	//	val++;
	//}
	//std::cout << "Sum =" << sum << std::endl;

	//return 0;
	//


	//?不定长while循环输入
	//int sum = 0, value = 0;
	//while (std::cin >> value) {
	//	sum += value;
	//}
	//std::cout << "sum =" << sum << std::endl;

	//return 0;

	//?############################################################################################ class引入
	//Sales_item book;
	//std::cin >> book;
	//std::cout << book << std::endl;
	//return 0;

	//?############################################################################################ 成员函数引入
	//Sales_item item1, item2;
	//std::cin >> item1 >> item2;
	//if (item1.isbn() == item2.isbn()) {
	//	std::cout << item1 + item2 << std::endl;
	//	return 0;
	//}
	//else {
	//	std::cerr << "Data must refer to same isbn" << std::endl;
	//	return -1;
	//}

	//?############################################################################################ 指针
	//?空指针
	//int *p1 = nullptr;

	//?void* 指针
	/*double obj = 3.14, * pd = &obj;
	void* pv = &obj;
	pv = pd;*/
	//!利用void*指针能做的事比较有限：和别的指针比较 | 作为函数的输入或输出 | 给另外一个void*赋值
	//!不能直接操作void*指针所指的对象，因为我们不知道这个对象是什么类型

	//?指向指针的引用
	/*int i = 42;
	int* p;
	int*& r = p;
	r = &i;
	*r = 0;*/

	//!默认状态下， const对象仅在文件内有效
	//!解决办法是， 不管是声明还是定义，都添加extern关键字
	//?见main上方

	//?指针和const
	//?指向常量的指针
	//const double pi = 3.14;   //pi是个常量。它的值不能改变
	////!double *ptr = &pi;      //错误， ptr是一个普通指针
	//const double* cptr = &pi; //正确
	////! *cptr = 42;             //错误， 不能给*cptr赋值
	
	//?const指针，常量指针
	//?把指针本身定为常量
	/*int errNumb = 0;
	int* const curErr = &errNumb;
	const double pi = 3.14159;
	const double* const pip = &pi;*/


	//?############################################################################################ 类型别名（type alias）         
	// typedef double wages, *p_w;
	// using SI = Sales_item;

    //?############################################################################################ auto类型说明符
    //?在将表达式赋给变量时，auto可以让编译器替我们分析表达式所属的类型

    //?############################################################################################ decltypr类型指示符
    //?用法：decltype(f()) sum(要定义的变量) = x;
    // const int ci = 0, &cj = ci;
    // decltype(ci) x = 0;         //x的类型是const int
    // decltype(cj) y = x;         //y的类型是const int&
    // decltype(cj) z              //错误：z是一个引用，必须初始化
    //!decltype 的表达式如果是加上了括号的变量，结果将是引用
    // decltype((i)) d;            //错误：d是int&，必须初始化

	Sales_data data;
	while (std::cin >> data.bookNo >> data.units_sold >> data.price) {
		data.revenue = data.units_sold * data.price;
	}

	//?############################################################################################ string
	//?string(include<string>)初始化方式
	string s1 = "hiya";
	string s2(10, 'c');
	string s3("hiya");
	
	//?读取string对象
	string s;
	cin >> s;
	cout << s << endl;
	return 0;

	//?while不定长
	string word;
	while (cin >> word) {
		cout << word << endl;
	}
	return 0;

	//?getline读取整一行
	string line;
	while (getline(cin, line)) {
		cout << line << endl;
	}
	return 0;*
	
	//?遍历字符串，检验符号字符
	string s("Hello World!!!");
	int punct_cnt = 0;
	for (auto c : s) {
		if (ispunct(c)) {
			++punct_cnt;
		}
	}
	//!typeid(variable).name()可以显示类型
	cout << typeid(s.size()).name() << endl;
	cout << punct_cnt << " punctuation characters in " << s << endl;
    
	//?使用引用直接更改字符串
	string s("Hello World!!!");
	for (auto& c : s) {
		c = toupper(c);
	}
	cout << s << endl;
	
	//?使用下标运算符
	string s("some string");
	if (!s.empty()) {
		s[0] = toupper(s[0]);
	}
	cout << s << endl;

	//?toupper+下标使用
	string s("some string");
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) {
		s[index] = toupper(s[index]);
	}
	cout << s << endl;

	//?数字序列转为16进制
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
		<< "separated by spaces. Hit ENTER when finished: "
		<< endl;
	string result;
	string::size_type n;
	//int n;
	while (cin >> n) {
		if (n < hexdigits.size()) {
	        //!字符的追加操作
			result += hexdigits[n];
		}
	}
	cout << "Your hex number is: " << result << endl;

	//?去除字符串中的字符
	string s("Hi!!! My World!!");
	string s_;
	/*for (decltype(s.size()) i = 0; i != s.size(); i++) {
		if (!ispunct(s[i])) {

		}
	}*/
	for (auto c : s) {
		if (!ispunct(c)) {
			s_ += c;
		}
	}
	cout << s_ << endl;

	//?############################################################################################ vector
	//?vector模板实例化为类
	vector<int> ivec;
	vector<Sales_data> Sales_vec;
	vector<vector<string>> file;

	//?vector初始化
	
	vector<T> v1
	vector<T> v2(v1)
	vector<T> v3(n, val)
	vector<T> v4(n)
	vector<T> v5{a,b,c}
	
	//?最常见的情况是，创建一个vector对象时并不清楚实际所需要的元素个数和值,
	//?这时使用pushback进行追加即可
	vector<int> v2;
	for (int i = 0; i != 100; i++) {
		v2.push_back(i);
	}
	//
	string word;
	vector<string> text;
	while (cin >> word) {
		text.push_back(word);
	}

	//?############################################################################################ 迭代器iterator
	string s("some thing");
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s << endl;

	for (auto it = s.begin(); it != s.end() && !isspace(*it); it++) {
		*it = toupper(*it);
	}
	cout << s << endl;

	//?iterator和const_iterator（常量迭代器）
	vector<int>::iterator it;         //能读写
	string::iterator it2;

	vector<int>::const_iterator it3;  //只能读
	string::const_iterator it4

	//!text为一个字符串向量，cbegin()、cend()产生常量迭代器 it->empty() 等价于 (*it).empty()
	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
		cout << *it << endl;
	}

	vector<int> text{ 1,2,4,6,8,9,13 };
	int sought = 2;

	decltype(begin) mid;
	while ((mid = begin + (end - begin) / 2) != end) {
		if (*mid == sought) {
			cout << sought << " is in the text" << endl;
			return 0;
		}
		if (sought < *mid) {
			end = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	cout << sought << " is not in the text" << endl;
	return 0;

	//?############################################################################################ 数组
	//?初始化数组
	const unsigned sz = 3;
	int ial[sz] = { 0,1,2 };
	int a2[] = { 0,1,2 };
	int a3[5] = { 0,1,2 };
	string a4[3] = { "hi", "bye" };
	
	//!字符数组有特殊的初始化方式
	char a1[] = { 'c','+','+' };
	char a2[] = { 'c','+','+','\0' };
	char a3[] = "c++";
	//!不嫩把一个数组直接复制给另一个数组

	int* ptrs[10];              //ptrs是含有10个整型指针的数组
	int& refs[10] = /*?*/;      //错误：不存在引用的数组
	int arr[10];
	int (*Parray)[10] = &arr;   //Parray指向一个含有10个整数的数组
	int(&arrRef)[10] = arr;     //arrRef引用一个含有10个整数的数组

	//!指针也是迭代器
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	++p;
	int* end = &arr[10];
	for (int* begin = arr; begin != end; ++begin) {
		cout << *begin << endl;
	}

	//?标准库函数begin和end，此处面向数组
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	int* pbegin = begin(ia);
	int* pend = std::end(ia);
	while (pbegin != pend && *pbegin >= 0) {
		++pbegin;
	}

	//?多维数组
	//?多维数组的初始化
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};
	/*int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	int ia[3][4] = { {0},{4},{8} };
	int ia[3][4] = { 0,3,6,9 };*/

	//?多维数组的下标引用
	//ia[2][3] = arr[0][0][0];
	//int(&row)[4] = ia[1];//!把row定义成一个含有4个整数的数组的引用

	//!使用范围for语句处理多维数组
	size_t cnt = 0;
	for (auto& row : ia) {
		for (auto& col : row) {
			col = cnt;
			++cnt;
		}
	}

	//!在上面的例子中，因为要改变数组元素的值，所以我们选用引用类型作为循环控制变量，
	//!但其实还有一个深层次原因促使我们这么做
	for (const auto& row : ia) {
		for (auto col : row) {
			cout << col << endl;
		}
	}
	//?这个循环中并没有写任何操作，可是我们还是将外层循环的控制变量声明成了引用类型，
	//!这是为了避免数组被自动转成指针
	//for (auto row : ia) {
	//	for (auto col : row) {
	//		/*?*/
	//	}
	//}
	//!程序将无法编译通过，因为row不是引用类型，所以编译器初始化row时会自动将这些数组形式
	//!的元素转换成指向该数组内首元素的指针，此时row的类型就是int*，显然内层的循环就不合法
	//?了

	//?############################################################################################ 数组指针
	int (*p)[4] = ia;
	cout << **(p+1) << endl;

	//?使用auto或者decltype就能避免在数组前面加上一个指针类型
	for (auto p = ia; p != ia + 3; ++p) {
		//!p指向含有4个整数的数组
		for (auto q = *p; q != *p + 4; ++q) {
			//!q指向4个整数数组的首元素，也就是说，q指向一个整数
			cout << *q << ' ';
			cout << endl;
		}
	}

	//?使用begin和end
	//!p指向ia的第一个数组
	for (auto p = begin(ia); p != end(ia); ++p) {
		//!q指向内层数组的首元素
		for (auto q = begin(*p); q != end(*p); ++q) {
			cout << *q << endl;
		}
	}

	//?############################################################################################ TRY语句块和异常处理
	Sales_item item1, item2;
	cin >> item1 >> item2;
	if (item1.isbn() != item2.isbn()) {
		throw std::runtime_error("Data must refer to same ISBN");
	}
	cout << item1 + item2 << endl;

	//?try语句块
	while (cin >> item1 >> item2) {
		try {
			cout << item1 + item2 << endl;
		}
		catch (std::runtime_error err) {
			cout << err.what()
				<< "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') {
				break;
			}
		}
	}

	//?############################################################################################ 函数
	//!引用返回左值
	char& get_val(string& str, string::size_type ix) {
		return str[ix];
	}

	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';
	cout << s << endl;

	//?############################################################################################ 测试Person代码
	//Person stu(cin);
	//cout << stu.name << " " << stu.address << endl;
	//print(cout, stu) << endl;

	//?############################################################################################ 使用作用域运算符直接访问静态成员
	/*double r;
	r = Account::rate();
	cout << r << endl;*/

	//?############################################################################################ IO库
	//!我们不能拷贝或对IO对象赋值
	//!读写一个IO对象会改变其状态，因此传递和返回的引用不能是const的
	
	//?刷新输出缓冲区
	cout << "hi!" << endl;        //输出 hi 和一个换行，然后刷新缓冲区
	cout << "hi!" << std::flush;  //输出 hi，然后刷新缓冲区，不附加任何额外字符
	cout << "hi!" << std::ends;   //输出 hi和一个空字符，然后刷新缓冲区

	//? unitbuf操作符
	//?每次输出操作后都刷新缓冲区
	cout << std::unitbuf;
	//?回到正常缓冲方式
	cout << std::nounitbuf;

	//?关联输入和输出流
	//?当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作
	//?都会先刷新关联的输出流。标准库将cout和cin关联在一起，因此下面语句
	
	//cin >> ival;

	//?导致cout的缓冲区被刷新

	//?tie有两个重载的版本。一个版本不带参数，返回指向输出流的指针。
	//?如果本对象当前关联到一个输出流。则返回的就是指向这个流的指针，
	//如果对象未关联到此ostream，则返回空指针。tie的第二个版本接受一
	//个指向ostream的指针，将自己关联到此ostream。即，x.tie(&o)将流
	//x关联到输出流。
	//我们既可以将一个istream对象关联到另一个ostream，也可以将一个
	//ostream关联到另一个ostream

	cin.tie(&cout);

	//?使用文件流对象
	std::ifstream in(ifile);

	//!在要求使用基类型对象的地方，我们可以用继承类型的对象来代替。
	//!这意味着，接受一个 iostream 类型引用（或指针）参数的函数，可
	//!以用一个对应的 fstream (或 sstream )类型来调用
	//!如 Sales_data 中的 read 和 print
	//! ifstream input(argv[1]); 
	//! ofstream output(argv[2]);
	//!可使用 read(input, total) 和 print(output, total)
	
	//?成员函数 open 和 close
	//?如果我们定义了一个空文件流，可以随后调用open来将它与文件关联起来
	string ifile = "NOT_EXIST.txt";
	std::ifstream in(ifile);
	std::ofstream out;
	out.open(ifile + ".copy");

	//?每个文件流都有一个关联的文件模式，用来指出如何使用文件
	//! in 以读方式打开
	//! out 以写方式打开
	//! app 每次操作前均定位到文件末尾
	//! ate 打开文件后立即定位到文件末尾
	//! trunc 截断文件
	//! binary 以二进制方式进行IO
	//! 
	//! ############################------> 指定文件模式有如下限制
	//! 
	//! 仅可以对 ofstream / fstream 设置 out
	//! 
	//! 仅可以对 ifstream / fstream 设置 in
	//! 
	//! 仅先设定 out 才可设定 trunc
	//! 
	//! 仅不设定 trunc 才可设定 app。在 app 模式下，即使没有显式指定
	//!out模式，文件也总是以输出方式被打开
	//! 
	//! 默认情况下，即使我们没有指定trunc，以 out 模式打开的文件也会被截断。
	//!为了保留以 out 模式打开的文件内容，我们必须同时指定app模式，这样只会
	//!将数据追加写到文件末尾；或者同时指定 in 模式，即打开文件同时进行读写
	//!操作
	//! 
	//! ate 和 binary 模式可用于任何类型的文件流对象，且可以与其他任何文件模
	//!式组合使用

	//?以out模式打开文件会丢弃已有数据
	//?默认情况下，当我们打开一个 ofstream 时，文件的内容会被丢弃。阻止一个 
	//?ofstream 清空给定文件内容的方法是同时指定 app 模式：
	//?在这几条语句中，file1都被截断
	std::ofstream out("file1");
	std::ofstream out2("file1", std::ofstream::out);
	std::ofstream out3("file1", std::ofstream::out | std::ofstream::trunc);
	//?为了保留文件内容，我们必须显示指定 app 模式
	std::ofstream app("file2", std::ofstream::app);
	std::ofstream app2("file2", std::ofstream::out | std::ofstream::app);

	//?每次调用open时都会确定文件模式
	std::ofstream out; //未指定文件打开模式
	out.open("scratchpad");
	out.close();
	out.open("precious", std::ofstream::app);
	out.close();

	//?string流
	//考虑这样一个例子，假定有一个文件，列出了一些人和他们的电话号码。
	//某些人只有一个号码，而另一些人则有多个---家庭电话、工作电话、移
	//动电话等。我们的输入文件看起来可能是这样的
	//Morgan 2015552368 8625550123
	//drew 973550130
	//lee 6095550132 2015550175

	/*struct PersonInfo {
		string name;
		vector<string> phones;
	};*/

	//使用istringstream
	string line, word;
	vector<PersonInfo> people;
	while (getline(cin, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	//?使用ostringstream
	//当我们逐步构造输出，希望最后一起打印时，ostringstream 是很有用的
	//例如，对上一节的例子，我们可能想逐个验证电话号码并改变其格式。如
	//果所有号码都是有效的，我们希望输出一个新的文件，包含改变格式后的
	//号码。对于那些无效的号码，我们将不会将它们输出到新文件中，而是打
	//印一条包含人名和无效号码的错误信息
	//由于我们不希望输出有无效电话号码的人，因此对每个人，直到验证完所
	//有电话号码后才可以进行输出操作。但是，我们可以先将输出内容“写入”
	//到一个内存 ostringstream 中

	for (const auto& entry : people) {
		std::ostringstream formatted, badNums;
		for (const auto& nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			}
			else {
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty()) {
			cout << entry.name << " " << formatted.str() << endl;
		}
		else {
			std::cerr << "input error: " << entry.name
				<< " invalid number(s) " << badNums.str() << endl;
		}
	}

	//?############################################################################################ 顺序容器
	//?这些容器在以下方面都有不同的性能折中
	//! 向容器添加或从容器中删除元素的代价
	//! 非顺序访问容器中元素的代价
	//! 
	//! vector 可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素
	//!	可能很慢
	//! 
	//! deque 双端队列。支持快速随机访问。在头尾位置插入/删除速度很快
	//! 
	//! list 双向链表。只支持双向顺序访问。在 list 中任何位置进行插入/删除
	//! 操作速度都很快
	//! 
	//! forward_list 单向链表。只支持单项顺序访问。在链表任何位置进行插入/删除
	//! 操作速度都很快
	//! 
	//! array 固定大小数组。支持快速随机访问，不能添加或删除元素
	//! 
	//! string 与 vector 相似的容器，但专门用于保存字符。随机访问快。在尾部
	//! 插入/删除速度快
	//! 
	//! P327 查看更多细节

	//?选择容器的基本原则
	//! 除非你有很好的理由选择其他容器，，否则应使用vector
	//! 
	//! 如果你的程序有很多小的元素，且空间的额外开销很重要，则不要使用 list
	//! 或 forward_list
	//! 
	//! 如果程序要求随机访问元素，应使用 vector 或 deque
	//! 
	//! 如果程序需要在中间插入或删除元素，应使用 list 或 forward_list
	//! 如果程序需要在头尾位置插入或删除元素，但不会在中间位置进行插入
	//! 或删除操作，则使用deque
	//! 
	//! 如果程序只有在读取输入时才需要在容器中间位置插入元素，随后需要随机访问
	//! 元素，则
	//! 首先，确定是否真的需要在容器中间位置添加元素。当处理输入数据时，通常
	//! 可以很容易地向 vector 追加数据，然后再调用标准库的 sort 函数来重排，
	//! 从而避免在中间位置添加元素
	//! 如果必须在中间位置插入元素，考虑在输入阶段使用list，一旦完成，将 list
	//! 中的内容拷贝到一个 vector 中

	//! 容器操作 P295

	//? 迭代器
	//? [begin, end)
	//? while(begin != end){
	//?		*begin = val;
	//?     ++begin;
	//? }

	//?############################################################################################ explicit P265

	//? 容器初始化
	//! C c(begin, end); c初始化为迭代器b和e指定范围中的元素的拷贝。范围中元素的
	//! 类型必须与c的元素类型相容（array不适用）
	//! 
	//! list<string> authors = {"Milton", "Shakespeare", "Austen"};
	//! vector<const char*> articles = {"a", "an", "the"};
	//! 
	//! list<string> list2(authors);        //正确：类型匹配
	//! deque<string> authList(authors);    //错误：容器类型不匹配
	//! forward_list<string> words(articles.begin(), articles.end());//正确：
	//! 可以将 const char* 元素转换为 string

	//! deque<string> svec(10);             //10个元素，每个都是空string
	//! 
	//! deque<string> svec(10, "hi!");             //10个元素，每个都初始化为"hi!"

	//? 赋值和swap
	//! c1 = c2; //? 如果两个容器原来大小不同，赋值运算后两者的大小
	//! 都与右边容器的原大小相同
	//! c1 = {a, b, c}
	
	//! 使用 assign (仅顺序容器)
	//! 顺序容器还定义了一个名为 assign 的成员
	//! 允许我们从一个不同但相容的类型赋值
	list<string> names;
	vector<const char*> oldstyle;
	names.assign(oldstyle.cbegin(), oldstyle.cend());

	//! assign的第二个版本接受一个整型值和一个元素值。它用指定数目
	//! 且具有相同给定值的元素替换容器中原有的元素
	list<string> slist1(1);                  //! 一个元素，为空string
	slist1.assign(10, "hiya!");    //! 10个元素，每个都是 "Hiya!"
	//等价于
	slist1.clear();
	slist1.insert(slist1.begin(), 10, "HIya!");
	
	//? 使用swap
	//? swap 操作交换两个类型相同的容器的内容。调用 swap 之后，两个容器中的
	//? 元素将会交换
	vector<string> svec1(10);
	vector<string> svec2(24);
	std::swap(svec1, svec2);

	//? 容器大小操作
	//? 除了forward_list
	//? 每个容器类型都有三个与大小相关的操作。成员函数size返回容器中元素的个数
	//? empty返回容器是否为空
	//? max_size返回一个大于或等于该类型容器所能容纳的最大元素值
	//? forward_list 支持 max_size 和 empty，但不支持 size。

	//? 关系运算符
	//? 每个容器类型都支持相等运算符(==和!=): 除了无序关联容器外的所有容器都支持
	//? 关系运算符(>、>=、<、<=0)。
	//? 比较两个容器实际上是进行元素的逐对比较。这些运算符的工作方式与 string 的
	//? 关系运算符类似。

	//! 若容器的元素类型不支持所需运算符，那么保存这种元素的容器就不能使用相应的
	//! 关系运算符
	
	//? 顺序容器操作
	//? 向顺序容器添加元素
	//! c.push_back(t)           //在c的尾部创建一个值为 t 或由 args 创建的元素
	//! c.emplace_back(args)
	//! 
	//! c.push_front(t)          //在c的头部创建一个值为 t 或由 args 创建的元素
	//! c.emplace_front(args)   
	//! 
	//! c.insert(p, t)           //在迭代器p指向的元素之前创建一个值为 t 或由 a
	//! c.emplace(p, args)       rgs 创建的元素。返回指向新添加的元素的迭代器
	//! 
	//! c.insert(p, n, t)        //在迭代器p指向的元素之前插入n个值为 t 的元素。
	//!                          返回指向新添加的第一个元素的迭代器。n为0，返p
	//! 
	//! c.insert(p, begin, end)  //将迭代器 b 和 e 指定的范围内的元素插入到迭代
	//!                          器p指向的元素之前。b\e 不来自于c，返回指向新添
	//!                          加的第一个元素的迭代器
	//! 
	//! c.insert(p,il)           //il是一个{ }包围的元素值列表。将这些给定值插入
	//!                          到迭代器p指向的元素之前，返回指向新添加的第一个
	//!                          元素的迭代器

	//! forward_list有自己专有版本的 insert 和 emplace

	//? 使用insert
	//? 虽然某些容器不支持push_front操作，但它们对于 insert 操作并无类似的限制
	//? 因此我们可以将元素插入容器的开始位置，而不必担心容器是否支持push_front
	vector<string> svec;
	svec.insert(svec.begin(), "Hello");

	//! 插入范围内元素
	/*svec.insert(svec.end(), 10, "Anna");
	vector<string> v = { "quasi", "simba", "frollo", "scar" };
	svec.insert(svec.begin(), v.end() - 2, v.end());
	svec.insert(svec.end(), { "quasi", "simba", "frollo", "scar" });*/

	//? 使用 insert 的返回值
	//? 通过使用 insert 的返回值，可以在容器中一个特定的位置反复插入元素
	/*list<string> lst;
	auto iter = lst.begin();
	string word;
	while (cin >> word) {
		iter = lst.insert(iter, word);
	}*/

	//? 使用 emplace 操作
	//! emplace_front()
	//! emplace(iter, argvs)
	//! emplace_back()
	//? 当调用 push 或 insert 成员函数时，我们将元素类型的对象传递给它们，
	//? 这些对象被拷贝到容器中。而当我们调用一个 emplace 成员函数时，则是
	//? 将参数传递给元素类型的构造函数。emplace 成员使用这些参数在容器管理
	//? 的内存空间中直接构造元素。
	//? 使用三个参数的 Sales_data 构造函数
	//c.emplace_back("978-0590353403", 25, 15.99);
	//? 可认为等价于
	//c.push_back(Sales_data("978-0590353403", 25, 15.99));

	//? 访问元素
	//! 除了 forward_list
	vector<string> c{"Hi"};
	if (!c.empty()) {
		auto val = *c.begin(); 
	    auto val2 = c.front();
		
		auto last = c.end();
		auto val3 = *(--last);
		auto val4 = c.back();
	}
	//? 在顺序容器中访问元素的操作
	//? at 和下标操作只适用于 string、vector、deque 和 array
	//? back 不适用于 forward_list
	//! c.back()          返回c中尾元素的引用。若 c 为空， 函数行为未定义
	//! c.front()         返回c中首元素的引用。
	//! c[n]
	//! c.at(n)
	
	//? 访问成员函数返回的是引用，我们可以用来改变元素的值
	if (!c.empty()) {
		c.front() = "Good";
		auto& v = c.back();
		v = "basic";
		auto v2 = c.back();  //! v2不是一个引用， 它是 c.back() 的一个拷贝
		v2 = 0;              //! 未改变c中的元素
	}

	
}