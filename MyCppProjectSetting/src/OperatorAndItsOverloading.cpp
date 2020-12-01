#include <iostream>
#include <string>

namespace OperatorAndOperatorOverloading
{
	struct Vector2
	{
		float x, y;

		Vector2(float x, float y)
			: x(x), y(y) {}

		Vector2 Add(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator +(const Vector2& other) const
		{
			return Add(other);
		}

		Vector2 Multiply(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}

		Vector2 operator *(const Vector2& other) const
		{
			return Multiply(other);
		}

		bool operator ==(const Vector2& other) const
		{
			return x == other.x && y == other.y;
		}

		bool operator !=(const Vector2& other) const
		{
			return x != other.x || y != other.y;
		}

		//std::ostream& operator<<(std::ostream& stream)
		//{
		//	stream << x << ", " << y;
		//	return stream;
		//}

	};
}

std::ostream& operator <<(std::ostream& stream, const OperatorAndOperatorOverloading::Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

/*
int main()
{
	using namespace OperatorAndOperatorOverloading;

	Vector2 position(1.0f, 2.0f);
	Vector2 speed(0.5f, 0.5f);
	Vector2 powerup(1.1f, 1.1f);

	//Vector2 result = position.Add(speed.Multiply(powerup));
	Vector2 result = position + speed * powerup;

	std::cout << result << std::endl;
}
*/