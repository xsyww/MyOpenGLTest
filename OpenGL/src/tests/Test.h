#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <functional>

namespace test 
{
	class Test
	{
	public:
		Test();
		virtual ~Test() {}

		virtual void OnUpdate(float deltaTime) {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}

		inline std::string GetName() const { return m_Name; }
		void SetName(const std::string& name);

	private: 
		std::string m_Name;
	};


	class TestMenu : public Test
	{
	public:
		TestMenu(Test*& currentTestPointer);

		void OnImGuiRender() override;

		template<typename T>
		void RegisterTest(const std::string& name)
		{
			std::cout << "Registering test " << name << std::endl;
			m_Tests.push_back(std::make_pair(name, [&]() { T* obj = new T(); obj->SetName(name); return obj; }));
		}

	private: 
		Test*& m_CurrentTest;
		std::vector<std::pair<std::string, std::function<Test* ()>>> m_Tests;
	};
}