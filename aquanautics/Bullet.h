#pragma once
class Bullet : public Object
{
private:
	Sprite* bullet;
	Collision* m_collision;

public:
	Bullet();
	~Bullet();

	bool Initialize();
	void Update(float deltaTime);
	void Render();
	int LifeTime;
	int deathTime;

	void IsCollisionWith(Collision* collision);
};

