#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;

public:
	const std::string& GetName() const
	{
		m_DebugCount++;	// 被修饰为mutable，可以无视函数的const属性
		return m_Name;
	}
};

int main1()
{
	const Entity e;
	e.GetName();	// 如果Entity类中，GetName函数不被标记为 const (指函数后面的const）那么这句就会出错。

	int x = 8;
	auto f = [=]() mutable // lamda 表达式
	{
		x++;
		std::cout << x << std::endl;
	};

	f();

	return 0;
}