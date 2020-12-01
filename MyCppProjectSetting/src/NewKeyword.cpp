#include <iostream>
#include <string>


namespace NewKeyword
{
	using String = std::string;

	class Entity
	{
	private:
		String m_Name;

	public:
		Entity() : m_Name("Unknown") {}
		Entity(const String& name) : m_Name(name) {}

		const String& GetName() const { return m_Name; }
	};

	int main()
	{
		using namespace NewKeyword;

		int a = 2;				// stack
		int* b = new int[50];	// heap 200bytes
		delete[] b;

		Entity* e = new Entity();	// allocate memory and call the constructor.

		delete e;					// do delete it!

		return 0;
	}

}


