#pragma once
#include "pch.h"
#include "SoundEffects.hpp"

using namespace sf;

extern int stagePhase;
extern int enemyCounter;
extern int stageBoss;
extern Vector2f PlayerPos;

//Stage 2 is made better in my opinion

void Stage1(std::vector<Bullet> &bullets, Texture *BulletTex, std::vector<Enemy> &enemies, Texture *enemy1Texture, float time)
{

	
	
	if (stagePhase == 0)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(60, -15), 270, 0.1, time, 30, 99, 0.5));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 10;
		}
	}
	else if (stagePhase == 1)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(730, -15), 270, 0.1, time, 24, 99, 0.5));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 5;
		}
	}

	else if (stagePhase == 2)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(-15, 30), 0, 0.1, time, 30, 1, 0.045));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 5;
		}
	}
	else if (stagePhase == 3)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(800, 30), 180, 0.1, time, 24, 1, 0.045));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 7;
		}
	}
	else if (stagePhase == 4)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(enemyCounter * 100, -15), 270, 0.05, time, 0, 2, 0.060));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 7;
		}
	}
	else if (stagePhase == 5)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(800 - enemyCounter * 100, -15), 270, 0.05, time, 0, 2, 0.060));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 3;
		}
	}
	else if (stagePhase == 6)
	{
		if (!(enemies.size() && bullets.size()))
		{
			stagePhase++;
		}
	}
	else if (stagePhase == 7)
	{
		switch (enemyCounter)
		{
		case 3:
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(400, -15), 270, 0.04, time, 0, 1, 0.065));
			enemyCounter--;
			break;
		}
		case 2:
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(100, -15), 270, 0.04, time, 0, 1, 0.065));
			enemyCounter--;
			break;
		}
		case 1:
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(700, -15), 270, 0.04, time, 0, 1, 0.065));
			enemyCounter--;
			break;
		}
		case 0:
		{
			stagePhase++;
			enemyCounter = 14;
			break;
		}
		}
	}
	else if (stagePhase == 8)
	{
		if (enemyCounter > 8)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(enemyCounter * 100 - 700, -15), 180 + enemyCounter * 10 - 70, 0.07, time, 0, 1.5, 0.055));
			enemyCounter--;

		}
		else if (enemyCounter)
		{
			enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(800 - enemyCounter * 100, -15), 330 - enemyCounter * 10, 0.07, time, 0, 1.5, 0.055));
			enemyCounter--;
		}
		else if (enemyCounter == 0)
		{
			stagePhase++;
			enemyCounter = 3;
		}
	}
	else if (stagePhase == 9)
	{
		if (enemyCounter)
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(enemyCounter * 200, -15), 270, 0.04, time, 0, 1.25, 0.065));
			enemyCounter--;
		}
		else
		{
			stagePhase++;
			enemyCounter = 21;
		}
	}
	else if (stagePhase == 10)
	{
		if (enemyCounter)
		{
			if (enemyCounter % 3 == 0)
			{
				enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(400, -15), 270, 0.055, time, 0, 1.5, 0.072));
				enemyCounter--;
			}
			else if (enemyCounter % 2 == 1)
			{
				enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(100, -15), 270, 0.095, time, 1, 1.3, 0.07));
				enemyCounter--;
			}
			else if (enemyCounter % 2 == 0)
			{
				enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14, Vector2f(700, -15), 270, 0.095, time, 17, 1.3, 0.07));
				enemyCounter--;
			}
		}
		else
		{
			stagePhase++;
			enemyCounter = 14;
		}
	}
	else if (stagePhase == 11)
	{
		if (enemyCounter == 10)
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(300, -15), 225, 0.055, time, 0, 1.2, 0.075));
		}
		if (enemyCounter == 7)
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(500, -15), 315, 0.055, time, 0, 1.2, 0.075));
		}
		if (enemyCounter == 4)
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(-15, 250), 315, 0.055, time, 0, 1.35, 0.070));
		}
		if (enemyCounter == 1)
		{
			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy21, RectEnemy22, RectEnemy23, RectEnemy24, Vector2f(800, 250), 225, 0.055, time, 0, 1.35, 0.070));
		}
		enemyCounter--;
		if (enemyCounter <= 0)
		{
			stagePhase++;
			enemyCounter = 10;
		}

	}
	else if (stagePhase == 12)
	{
		if (enemies.size() == 0 && bullets.size() == 0)
		{
			stagePhase = 999;
			stageBoss = 1;
			
		}
	}
}
void Stage1Boss(std::vector<Bullet> &bullets, Texture *BulletTex, std::vector<Boss> &bosses, Texture *enemy1Texture, float time, std::vector<SoundEffect> &Sound)
{
	
	if (stagePhase == 3)
	{
		Sound[3].playSound(50);

		bosses[0].speed = 0;
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.1, 36);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.3, 12);
	}
	else if(stagePhase == 4)
	{
	
		bosses[0].speed = 0.05;
		bosses[0].moving = 2;
		bosses[0].angle = 190;
	}
	else if (stagePhase == 8)
	{
		Sound[3].playSound(50);
		bosses[0].speed = 0;
		bosses[0].moving = 0;
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.1, 36);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.3, 12);

	}
	else if (stagePhase == 10)
	{
		bosses[0].speed = 0.1;
		bosses[0].moving = 1;
		bosses[0].angle = 350;
	}
	else if (stagePhase == 15)
	{
		bosses[0].speed = 0;
		bosses[0].moving = 0;
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.1, 36);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.3, 12);

	}
	else if (stagePhase == 18)
	{
		bosses[0].speed = 0.08;
		bosses[0].moving = 2;
		bosses[0].angle = 170;
	}
	else if (stagePhase == 20)
	{
		Sound[4].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.35, 8);
	}
	else if (stagePhase == 21)
	{
		Sound[4].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.35, 8);
	}
	else if (stagePhase == 22)
	{
		Sound[4].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.35, 8);
	}
	else if (stagePhase == 26)
	{
		bosses[0].speed = 0;
		bosses[0].moving = 0;
		Sound[3].playSound(50);
		for (int i = 0; i < 26; i++)
		{
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 20), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.06 + (float)i / 100));
		}
	}
	else if (stagePhase == 27)
	{
		Sound[3].playSound(50);
		for (int i = 0; i < 26; i++)
		{
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 25), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.06 + (float)i/100));
		}
	}
	else if (stagePhase == 28)
	{
		Sound[3].playSound(50);
		for (int i = 0; i < 26; i++)
		{
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.06 + (float)i / 100));
		}
	}
	else if (stagePhase == 29)
	{
		bosses[0].speed = 0.09;
		bosses[0].angle = 345;
		bosses[0].moving = 1;
	}
	else if (stagePhase == 32)
	{
		for (int i = 0; i < 3; i++)
		{
			Sound[4].playSound(50);
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.2 + (float)i / 50));
		}
	}
	else if (stagePhase == 33)
	{
		for (int i = 0; i < 3; i++)
		{
			Sound[4].playSound(30);
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.2 + (float)i / 50));
		}
	}
	else if (stagePhase == 34)
	{
		for (int i = 0; i < 3; i++)
		{
			Sound[4].playSound(30);
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.2 + (float)i / 50));
		}
	}
	else if (stagePhase == 35)
	{
		for (int i = 0; i < 3; i++)
		{
			Sound[4].playSound(30);
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.2 + (float)i / 50));
		}
		bosses[0].speed = 0;
		bosses[0].moving = 0;
	}
	else if (stagePhase == 37)
	{
		bosses[0].speed = 0.05;
		bosses[0].angle = 95;
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
		Sound[3].playSound(50);
	}
	else if (stagePhase == 38)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
	}
	else if (stagePhase == 39)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
	}
	else if (stagePhase == 40)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
	}
	else if (stagePhase == 41)
	{
		bosses[0].speed = 0;
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
	}
	else if (stagePhase == 43)
	{
		bosses[0].speed = 0.25;
		bosses[0].angle = 180;
	}
	else if (stagePhase == 45)
	{
		Sound[1].playSound(50);
		bosses[0].speed = 0;
	}

	else if (stagePhase == 48)
	{
		Sound[2].playSound(55);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 60);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.17, 36);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.23, 14);
		for (int i = 0; i < 11; i++)
		{
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x + 26, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.25 + (float)i / 25));
		}
		for (int i = 0; i < 11; i++)
		{
			bullets.push_back(Bullet(BulletTex, Bullet1, Vector2f(bosses[0].pos.x - 14, bosses[0].pos.y + 30), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.25 + (float)i / 25));
		}
	}
	else if (stagePhase  == 50)
	{
		bosses[0].speed = 0.45;
		bosses[0].angle = 345;
	}
	
	else if (stagePhase == 51)
	{
		bosses[0].speed = 0;	
	}
	else if (stagePhase == 55)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.15, 20);
	}
	else if (stagePhase == 58)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.15, 20);
		bosses[0].speed = 0.04;
		bosses[0].angle = 265;
	}
	else if (stagePhase >= 59 && stagePhase %6 == 0)
	{
		bosses[0].speed = 0;
	}
	else if (stagePhase >= 59 && stagePhase % 6 == 1)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.15, stagePhase > 80 ? stagePhase - 50 : 30);
	}
	else if (stagePhase >= 59 && stagePhase % 6 == 2)
	{
		bosses[0].speed = 0.2;
		bosses[0].angle = 0;
	}
	else if (stagePhase >= 59 && stagePhase % 6 == 3)
	{
		bosses[0].speed = 0;
		
	}
	else if (stagePhase >= 59 && stagePhase % 6 == 4)
	{
		Sound[3].playSound(50);
		bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.15, stagePhase > 80 ? stagePhase - 45 : 30);
	}
	else if (stagePhase >= 59 && stagePhase % 6 == 5)
	{
		bosses[0].speed = 0.2;
		bosses[0].angle = 180;
	}
	stagePhase++;
}