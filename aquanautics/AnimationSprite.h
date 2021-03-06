#pragma once
class AnimationSprite : public Sprite
{
private:
	std::vector<Sprite*> spriteList;

	int lastFrame;

	int frameDelay;

public:
	AnimationSprite(int frameSize , int frameDelay);
	~AnimationSprite();

	void AddFrame(Sprite* sprite);

	void SetCurrentFrame(int frame);

	void NextFrame();

	bool AutoNext;

	Sprite* GetCurrentFrame();

	int currentFrame;
	void Update(float deltaTime);
	void Render();
};

