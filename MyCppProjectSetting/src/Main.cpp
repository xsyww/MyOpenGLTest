#include <iostream>
#include <string>
#include "Entity.h"
#include <stdlib.h>


void TestConst()
{
	const int MAX_AGE = 90;
	int* a = new int;

	*a = 2;
	std::cout << a << std::endl;

	//a = &MAX_AGE; // 不可以，错误因为const
	a = (int*)&MAX_AGE;	// 强制转换后可以

	const int* b = new int;	// 说明你不可以修改指针b所指向的内容,如下面一句  【const 所修饰的是 int*】
	//*b = 2;	// 报错
	b = (int*)&MAX_AGE;	// 但是你仍然可以修改b的值（也就是地址）


	int* const c = new int; // 和上面一段相反，这种const 指定的是你不可以修改指针c的值，（也就是不能改变c所指向的地址），【const 所修饰的是 c】
	*c = 2;		// 但是你可以修改指针c所指向地址的那个值
	//c = (int*)&MAX_AGE;	// 不能改变c的值

	int const* d = new int; // 和第一种情况一样 和 const int* d = new int; 一样的。

	const int* const e = new int; // 什么都不能改
}

class MyEntity
{
private: 
	int m_X, m_Y;
	mutable int m_var;

public:
	int GetX() const	// 这个const说明此函数中没有任何修改成员的操作。
	{
		//m_X = 2; //这个操作和const冲突
		m_var = 3;	// 被mutable修饰的成员可以无视函数的const契约。
		return m_X;
	}
};


void TestString()
{
	std::string name = "xsyww";
	bool find = name.find("no") == std::string::npos;

	const char name11[8] = "Che\0rno";
	std::cout << name11 << std::endl;

	const char* name0 = u8"xsyww";
	const wchar_t* name1 = L"xsyww";
	const char16_t* name2 = u"xsyww";
	const char32_t* name3 = U"xsyww";
}

class TestEntity
{
public:
	float X, Y;

	TestEntity()
	{
		X = 0;
		Y = 0;
		std::cout << "Created Entity" << std::endl;
	}

	TestEntity(float x, float y)
	{
		X = x;
		Y = y;
		std::cout << "Created Entity" << std::endl;
	}

	~TestEntity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

class Log
{
//private:	// 两种不允许访问默认构造函数的办法，一种就是把构造函数设置为private
//	Log() {}

public:
	Log() = delete;	// 另一种就是这个，让它=delete

	static void Write(const char* message)
	{
		std::cout << message << std::endl;
	}
};

void Print(Printable* p)
{
	std::cout << p->GetClassName() << std::endl;
}

void TestArray()
{
	int example[5];	// stack can auto free
	int* ptr = example;
	for (int i = 0; i < 5; i++)
		example[i] = 2;

	example[2] = 5;
	*(ptr + 2) = 6;
	*(int*)((char*)ptr + 8) = 7;

	int* another = new int[5];	// heap, should free manully
	for (int i = 0; i < 5; i++)
		another[i] = 2;
	delete[] another;

	std::cout << example[0] << std::endl;
	std::cout << example << std::endl;
}




