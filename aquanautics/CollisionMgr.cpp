#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
	collisionList.reserve(10);
	printf("CollisionMgr 생성 \n");

	collisionList.clear();
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::Initialize()
{
	return true;
}

void CollisionMgr::Update(float deltaTime)
{
	std::vector<Collision*>::iterator iter;

	iter = collisionList.begin();
	while (iter != collisionList.end())
	{
		if (((*iter)->Parent->visible) == false)
		{
			iter = collisionList.erase(iter);
			continue;
		}

		++iter;
	}

	for (auto a : collisionList)
		for (auto b : collisionList)
		{
			if (a != b)
			{
				//printf("A Name : %s \n", a->Parent->Name.c_str());
				//printf("B Name : %s \n", b->Parent->Name.c_str());
				if (CircleCollide(a, b))
				{
					a->IsCollide(b);
					b->IsCollide(a);
				}
			}
		}



	Object::Update(deltaTime);
}

void CollisionMgr::Render()
{
}

void CollisionMgr::RegisterCollision(Collision * collision)
{
	collisionList.push_back(collision);
}

bool CollisionMgr::CircleCollide(Collision * a, Collision * b)
{
	float ax = a->Parent->Position.x;
	float ay = a->Parent->Position.y;

	float bx = b->Parent->Position.x;
	float by = b->Parent->Position.y;

	//printf("ax : %f\n", ax);
	//printf("ay : %f\n", ay);

	//printf("bx : %f\n", bx);
	//printf("by : %f\n", by);

	if (a->Parent->Name == "urak")
	{
	//	printf("Name : %s , X : %f, Y : %f\n", a->Parent->Name.c_str(), ax, ay);
	//	printf("Name : %s , X : %f, Y : %f\n", b->Parent->Name.c_str(), ax, ay);
	}

	float ftemp = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

	if (ftemp <= (a->radius + b->radius))
		return true;

	//printf("Ftemp : %f\n", ftemp);

	return false;
}
//for (auto a : collisionList)// 1 2 3
//{
//	if (a == false)
//		continue;

//	printf("Collision : %s\n", a->Parent->Name.c_str());
//	if (a->Parent->visible == false)
//	{
//		std::vector<Collision*>::iterator iter = std::find(collisionList.begin(), collisionList.end(), a);
//		printf("충돌체 : %s 삭제\n", a->Parent->Name.c_str());
//		collisionList.erase(iter);
//	}

//	else
//		printf("else\n");
//}
//