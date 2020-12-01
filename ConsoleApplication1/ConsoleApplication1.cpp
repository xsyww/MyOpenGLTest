// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetName()
{
	return "LionHeart";
}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;

public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

int main()
{
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	DeviceManager dm;
	const auto& devices = dm.GetDevices();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
