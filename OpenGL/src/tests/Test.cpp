#include "Test.h"
#include "../vendor/imgui/imgui.h"

namespace test
{
	Test::Test()
		:m_Name(u8"")
	{

	}

	void Test::SetName(const std::string& name)
	{
		m_Name = name;
	}

	TestMenu::TestMenu(Test*& currentTestPointer)
		: m_CurrentTest(currentTestPointer)
	{
	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : m_Tests)
		{
			if (ImGui::Button(test.first.c_str()))
				m_CurrentTest = test.second();
		}
	}
}


