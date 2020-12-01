#include <iostream>
#include <string>

namespace CreateObject
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
		CreateObject::Entity* pEntity;
		{
			CreateObject::Entity entity;	// create in stack
			pEntity = &entity;
			std::cout << entity.GetName() << std::endl;
		}
		pEntity->GetName();	// error  entity was freed!

		{
			CreateObject::Entity* entity = new CreateObject::Entity("xsyww");	// create in heap
			pEntity = entity;
		}
		pEntity->GetName(); // ok, entity still there!
		delete pEntity;

		return 0;
	}
}



