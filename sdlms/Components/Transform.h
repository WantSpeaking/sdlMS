#pragma once

#include "Components/Component.h"

class Transform : public Component
{
private:
	SDL_FPoint position;
	float rotation;
	int flip;
	bool camera = false;

public:
	Transform();
	Transform(float x, float y, bool camera = false);
	~Transform();

	SDL_FPoint get_position() const;
	float get_rotation() const;
	int get_flip() const;
	auto get_camera() { return camera; };

	void set_position(const SDL_FPoint &value);
	void set_rotation(const float &value);
	void set_flip(const int value);
};
