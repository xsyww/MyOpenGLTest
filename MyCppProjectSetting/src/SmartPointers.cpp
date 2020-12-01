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
			// unique_ptr ������ͨ������ָ�룬������������ķ�Χ����Ч�����������ܱ�������
			// ��Ϊ��������ָ��ܿ�����Ϊԭʼ��ָ�볬��Χ�����ͷŵ���
			std::unique_ptr<Entity> entity(new Entity());
			std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();	// ���ֹ��췽�������׳��쳣
			//std::unique_ptr<Entity> entity3 = new Entity(); // �����ԣ������Ը�ֵ
			entity->Print();
			entity->Print();
			//entity2 = entity;	// �����ܿ��������ܸ���

			// shared_ptr��һ���ڽ����ü���������ָ�룬�����Ա����ƣ������ü���Ϊ0ʱ���Զ��ͷ�
			std::shared_ptr<Entity>e0;
			{
				std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
				e0 = sharedEntity;	// ��Ȼ���� ����+1
			}	// sharedEntity ����������-1

			// weak_prt��һ�������ã������ᵼ�����ü�������
			std::weak_ptr<Entity>e1;
			{
				std::shared_ptr<Entity> sEntity = std::make_shared<Entity>();
				e1 = sEntity;	// ��Ȼ���� ������������
			}// sEntity���� ����-1�� =0�ͷ��ڴ�

		}// e0 ����������-1��Ϊ0���ͷ��ڴ�

		return 0;

	}
}

