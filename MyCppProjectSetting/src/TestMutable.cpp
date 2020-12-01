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
		m_DebugCount++;	// ������Ϊmutable���������Ӻ�����const����
		return m_Name;
	}
};

int main1()
{
	const Entity e;
	e.GetName();	// ���Entity���У�GetName�����������Ϊ const (ָ���������const����ô���ͻ����

	int x = 8;
	auto f = [=]() mutable // lamda ���ʽ
	{
		x++;
		std::cout << x << std::endl;
	};

	f();

	return 0;
}