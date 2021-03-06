#include "stdafx.h"
#include "EnemySpawner.h"
#include"Urak.h"
#include"Eel.h"
#include"Shark.h"
#include"Kraken.h"

EnemySpawner::EnemySpawner() : IsHydra(0) ,IsShark(0)
{
}


EnemySpawner::~EnemySpawner()
{
}

bool EnemySpawner::Initialize()
{
	Object::Initialize();

	return true;
}

void EnemySpawner::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

void EnemySpawner::Render()
{
	Object::Render();
}

void EnemySpawner::SpawnEnemy(int x, int y)
{
	srand(time(NULL));
	auto r = (rand() % 2) + 1;
	printf("R : %d\n", r);
	switch (r)
	{
	case 1:
	{
		auto e = new Urak();
		e->Initialize();
		AddChild(e);
		e->SetPostion(x, y);
	}
	break;

	case 2:
	{
		auto e = new Eel();
		e->Initialize();
		AddChild(e);
		e->SetPostion(x, y);
	}
	break;

	default:
		printf("Spawner Default\n");
		break;
	}
}

void EnemySpawner::SpawnShark(int x, int y)
{
	shark = new Shark();
	shark->Initialize();

	AddChild(shark);

	shark->SetPostion(x, y);
}

void EnemySpawner::SpawnKraken(int x, int y)
{
}

void EnemySpawner::Remove(Object * child)
{
	//auto iter = std::find(Children.begin(), Children.end(), child);

	//if (iter == Children.end())
	//	return;

	//Children.erase(iter);
	child->Destroy();
}