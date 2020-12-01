#include <iostream>
#include <string>

namespace Constructor
{
	class Example
	{
	public:
		Example()
		{
			std::cout << "Created Entity!" << std::endl;
		}

		Example(int x)
		{
			std::cout << "Create Entity with " << x << "!" << std::endl;
		}
	};


	class Entity
	{
	private:
		std::string m_Name;
		Example m_Example;

	public:
		Entity()
		{
			m_Name = "Unknown";
			m_Example = Example(8);
		}

		Entity(const std::string& name)
			: m_Name(name), m_Example(8)
		{
		}

		const std::string& GetName() const { return m_Name; }
		void Print() const { std::cout << m_Name << std::endl; }
	};



	int main3()
	{
		Entity e;	// Example�Ĺ��캯����ִ��������

		Entity e0("xsyww");	// Example�Ĺ��캯��ִֻ��һ��

		return 0;
	}
}

