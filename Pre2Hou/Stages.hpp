#pragma once
#include "Objects.hpp"

void stage1(double time)
{
	if (time < 10)
	{
		enemies.push_back(Enemy(&enemyTex, window.getSize()));
	}
}