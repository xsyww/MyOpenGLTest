#include <iostream>
#include <string>

namespace ImplicitAndExplicitConversion
{
	class Entity
	{
	private:
		std::string m_Name;
		int m_Age;

	public:
		Entity(const char* name) : m_Name(name), m_Age(-1) {}
		Entity(const std::string& name) : m_Name(name), m_Age(-1) {}
		Entity(int age) : m_Name("Unknown"), m_Age(age) {}

		// explicit 关键字强制不允许隐式转换的发生，如果加上这个,main函数中的Entity d = 21; 这一句就出错。
		// 同样的PrintEntity(22)也不被允许了。
		//explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}

		const std::string& GetName() const { return m_Name; }
		int GetAge() const { return m_Age; }
	};

	void PrintEntity(const Entity& entity)
	{
		std::cout << entity.GetName() << " " << entity.GetAge() << std::endl;
	}

	int main()
	{
		using namespace ImplicitAndExplicitConversion;

		Entity a("xsyww");
		Entity b(22);

		Entity c = "LionHeart";	// still ok!
		Entity d = 21;

		PrintEntity(a);
		PrintEntity(b);
		PrintEntity(c);
		PrintEntity(d);

		PrintEntity(22); // still ok!!!!

		return 0;
	}
}


