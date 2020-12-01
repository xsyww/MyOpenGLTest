#include <iostream>
#include <string>

namespace KeywordThis
{
	class Entity;
	void PrintEntity(const Entity& entity);

	class Entity
	{
	public: 
		int x, y;

		Entity(int x, int y)
		{
			this->x = x;
			this->y = y;

			Entity& e = *this;
			PrintEntity(*this);
		}

		int GetX() const
		{
			const Entity& e = *this;

			return x;
		}
	};

	void PrintEntity(const Entity& entity)
	{
		// Print
	}
}