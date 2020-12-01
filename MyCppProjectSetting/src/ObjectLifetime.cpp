#include <iostream>
#include <string>

namespace ObjectLifetime
{
	class Entity
	{
	public:
		Entity()
		{
			std::cout << "Created Entity!" << std::endl;
		}

		~Entity()
		{
			std::cout << "Destroyed Entity!" << std::endl;
		}
	};

	class ScopedPtr
	{
	private: 
		Entity* m_Ptr;
		
	public:
		ScopedPtr(Entity* ptr)
			: m_Ptr(ptr)
		{
		}

		~ScopedPtr()
		{
			delete m_Ptr;
		}
	};

	int* CreateArray()
	{
		int array[50];
		return array;		// wrong!! array is gone!
	}

	ObjectLifetime::Entity CreateEntity()
	{
		return ObjectLifetime::Entity();
	}

}


//int main()
//{
//	using namespace ObjectLifetime;
//
//	{
//		ScopedPtr e = new Entity();
//	}
//
//
//	std::cin.get();
//}