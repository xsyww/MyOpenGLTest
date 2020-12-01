#include <iostream>
#include <string>

namespace ArrowOperator
{
	class Entity
	{
	public: 
		int x;

	public:
		void Print() const
		{
			std::cout << "Hello" << std::endl;
		}
	};

	class ScopedPtr
	{
	private: 
		Entity* m_Obj;

	public:
		ScopedPtr(Entity* entity)
			: m_Obj(entity)
		{}

		~ScopedPtr()
		{
			delete m_Obj;
		}

		Entity* GetObject() const
		{
			return m_Obj;
		}

		Entity* operator->()
		{
			return m_Obj;
		}

		const Entity* operator->() const
		{
			return m_Obj;
		}
	};

	struct Vector3
	{
		float x, y, z;
	};

	void main()
	{
		using namespace ArrowOperator;
		Entity e;
		e.Print();

		Entity* ptr = &e;
		Entity& entity = *ptr;
		ptr->Print();	//(*ptr).Print();
		ptr->x = 1;

		ScopedPtr entPtr = new Entity();
		entPtr->Print();

		int offset = (int)&(((Vector3*)0)->y);
		std::cout << offset << std::endl;
	}
}

