#include <iostream>
#include <string>
#include <memory>

namespace SmartPointers
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

		void Print()
		{

		}
	};

	int main()
	{
		using namespace SmartPointers;

		{
			// unique_ptr 就是普通的智能指针，它尽在它定义的范围内有效，但是它不能被拷贝！
			// 因为被拷贝的指针很可能因为原始的指针超范围而被释放掉。
			std::unique_ptr<Entity> entity(new Entity());
			std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();	// 这种构造方法可以抛出异常
			//std::unique_ptr<Entity> entity3 = new Entity(); // 不可以，不可以赋值
			entity->Print();
			entity->Print();
			//entity2 = entity;	// 错误不能拷贝，不能复制

			// shared_ptr是一个内建引用计数的智能指针，它可以被复制，当引用计数为0时，自动释放
			std::shared_ptr<Entity>e0;
			{
				std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
				e0 = sharedEntity;	// 当然可以 计数+1
			}	// sharedEntity 结束，计数-1

			// weak_prt是一个若引用，它不会导致引用计数增加
			std::weak_ptr<Entity>e1;
			{
				std::shared_ptr<Entity> sEntity = std::make_shared<Entity>();
				e1 = sEntity;	// 当然可以 但计数不增加
			}// sEntity结束 计数-1， =0释放内存

		}// e0 结束，计数-1，为0，释放内存

		return 0;

	}
}

