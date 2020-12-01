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

	//a = &MAX_AGE; // �����ԣ�������Ϊconst
	a = (int*)&MAX_AGE;	// ǿ��ת�������

	const int* b = new int;	// ˵���㲻�����޸�ָ��b��ָ�������,������һ��  ��const �����ε��� int*��
	//*b = 2;	// ����
	b = (int*)&MAX_AGE;	// ��������Ȼ�����޸�b��ֵ��Ҳ���ǵ�ַ��


	int* const c = new int; // ������һ���෴������const ָ�������㲻�����޸�ָ��c��ֵ����Ҳ���ǲ��ܸı�c��ָ��ĵ�ַ������const �����ε��� c��
	*c = 2;		// ����������޸�ָ��c��ָ���ַ���Ǹ�ֵ
	//c = (int*)&MAX_AGE;	// ���ܸı�c��ֵ

	int const* d = new int; // �͵�һ�����һ�� �� const int* d = new int; һ���ġ�

	const int* const e = new int; // ʲô�����ܸ�
}

class MyEntity
{
private: 
	int m_X, m_Y;
	mutable int m_var;

public:
	int GetX() const	// ���const˵���˺�����û���κ��޸ĳ�Ա�Ĳ�����
	{
		//m_X = 2; //���������const��ͻ
		m_var = 3;	// ��mutable���εĳ�Ա�������Ӻ�����const��Լ��
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
//private:	// ���ֲ��������Ĭ�Ϲ��캯���İ취��һ�־��ǰѹ��캯������Ϊprivate
//	Log() {}

public:
	Log() = delete;	// ��һ�־������������=delete

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




