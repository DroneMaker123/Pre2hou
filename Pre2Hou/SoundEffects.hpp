#pragma once
#include "pch.h"

class SoundEffect
{
public:
	sf::SoundBuffer SoundsBuffer;
	sf::Sound SoundEffectTrigger1;
	
	SoundEffect(String s)
	{
		this->SoundsBuffer.loadFromFile(s);
	}
	~SoundEffect() {}
	void playSound(int value)
	{
		this->SoundEffectTrigger1.setBuffer(this->SoundsBuffer);
		this->SoundEffectTrigger1.setVolume(value);
		this->SoundEffectTrigger1.play();
	}
};