#include <iostream>
#include <string>
#include <vector>

namespace DynamicArray
{
	struct Vertex
	{
		float x, y, z;
	};

	std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
	{
		stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
		return stream;
	}

	void Function(const std::vector<Vertex>& vertices)
	{
		
	}
}

void main()
{
	using namespace DynamicArray;

	std::vector<Vertex> vertices;
	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	Function(vertices);

	vertices.erase(vertices.begin() + 1);
	vertices.clear();
}