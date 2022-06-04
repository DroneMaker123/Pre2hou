#pragma once
#include "pch.h"
#include "SoundEffects.hpp"

using namespace sf;

extern int stagePhase;
extern int enemyCounter;
extern int stageBoss;
extern Vector2f PlayerPos;

void Stage2(std::vector<Bullet> &bullets, Texture *BulletTex, std::vector<Enemy> &enemies, Texture *enemy1Texture, float time, std::vector<SoundEffect> &Sound)
{
	switch (stagePhase)
	{
	case 50:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(60, -15), 270, 0.05, time, 30, 99, 0.5));
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(730, -15), 270, 0.05, time, 30, 99, 0.5));
		stagePhase++;
		break;
	}
	case 58:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(60, -15), 270, 0.05, time, 30, 99, 0.5));
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(730, -15), 270, 0.05, time, 30, 99, 0.5));
		stagePhase++;
		break;
	}

	case 64:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(60, -15), 270, 0.05, time, 30, 99, 0.5));
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(730, -15), 270, 0.05, time, 30, 99, 0.5));
		stagePhase++;
		break;
		
	}
	case 75:
	{
		if (enemies.size() > 0)
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (time - enemies[i].SpecialTimer > 3.5)
				{
					Sound[4].playSound(40);
					bulletsHell2(bullets, BulletTex, Vector2f(enemies[i].pos.x + 4, enemies[i].pos.y + 5), 0.1, 4, getNewAngle(enemies[i].pos, PlayerPos) - 30, getNewAngle(enemies[i].pos, PlayerPos) + 30, BulletIceShard);
					enemies[i].SpecialTimer = time;
				}
			}
		}
		else
		{
			stagePhase++;
		}
		break;
	}
	case 80:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(300, -15), 255, 0.05, time, 27, 1, 0.05));
		stagePhase++;
		break;
	}
	case 81:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(500, -15), 285, 0.05, time, 27, 1, 0.05));
		stagePhase++;
		break;
	}
	case 82:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(300, -15), 255, 0.05, time, 28, 1, 0.05));
		stagePhase++;
		break;
	}
	case 83:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(500, -15), 285, 0.05, time, 26, 1, 0.05));
		stagePhase++;
		break;
	}
	case 84:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(300, -15), 255, 0.05, time, 29, 1, 0.05));
		stagePhase++;
		break;
	}
	case 85:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(500, -15), 285, 0.05, time, 25, 1, 0.05));
		stagePhase++;
		break;
	}
	case 86:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(300, -15), 255, 0.05, time, 30, 1, 0.05));
		stagePhase++;
		break;
	}
	case 87:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(500, -15), 285, 0.05, time, 24, 1, 0.05));
		stagePhase++;
		break;
	}
	case 88:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(300, -15), 255, 0.05, time, 31, 1, 0.05));
		stagePhase++;
		break;
	}
	case 89:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(500, -15), 285, 0.05, time, 23, 1, 0.05));
		stagePhase++;
		break;
	}
	case 90:
	{
		if (enemies.size() == 0)
		{
			stagePhase++;
		}
		break;
	}

	case 91:
	{
		Sound[3].playSound(75);
		for (int i = 0; i < 10; i++)
		{
			bulletsHell2(bullets, BulletTex, Vector2f(-10, -10), 0.05 + 0.01*i, 6, 270, 360, BulletIceShard);

			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(-15, -15), 315, 0.04 + 0.005*i, time, 0, 3 + 0.1*i, 0.06));
		}
		stagePhase++;
		break;
	}
	case 100:
	{
		Sound[3].playSound(75);
		for (int i = 0; i < 10; i++)
		{
			bulletsHell2(bullets, BulletTex, Vector2f(800, -10), 0.05 + 0.01*i, 6, 180, 270, BulletIceShard);

			enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(799, -15), 225, 0.04 + 0.005*i, time, 0, 3 + 0.1*i, 0.06));
		}
		stagePhase++;
		break;
	}
	case 101:
	{
		if (bullets.size() == 0)
		{
			stagePhase++;
		}
		break;
	}
	case 102:
	{
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(100, -15), 270, 0.07, time, 0, 3 , 0.06));
		enemies.push_back(Enemy(5, enemy1Texture, RectEnemy31, RectEnemy32, RectEnemy33, RectEnemy34, Vector2f(700, -15), 270, 0.07, time, 0, 3 , 0.06));
		enemies.push_back(Enemy(30, enemy1Texture, RectEnemy41, RectEnemy42, RectEnemy43, RectEnemy44, Vector2f(400, -15), 270, 0.06, time, 0, 99, 0.06));
		stagePhase++;
		break;
	}
	case 110:
	{
		if (enemies.size() > 0)
		{
			
			if (time - enemies.back().SpecialTimer > 0.3 && bullets.size() < 300)
			{
				Sound[2].playSound(25);
				bulletsHell2(bullets, BulletTex, Vector2f(enemies.back().pos.x + 7, enemies.back().pos.y + 10), 0.1, 5, 270+ enemies.back().bulletUsed*30 - 22, 270 + enemies.back().bulletUsed * 30 + 22, BulletIceShard);
				enemies.back().speed = 0;
				enemies.back().bulletUsed++;
			}
		}
		else if(bullets.size() == 0)
		{
			stagePhase++;
		}
		break;
	}
	case 111:
	{
		Sound[5].playSound(50);
		setLaser(bullets, BulletTex, Vector2f(100, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 113:
	{
		setLaser(bullets, BulletTex, Vector2f(100, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 115:
	{
		

		setLaser(bullets, BulletTex, Vector2f(100, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 117:
	{
		Sound[5].playSound(50);
		setLaser(bullets, BulletTex, Vector2f(700, -15), BulletLaser1);
		setLaser(bullets, BulletTex, Vector2f(100, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 119:
	{
		setLaser(bullets, BulletTex, Vector2f(700, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 121:
	{
		setLaser(bullets, BulletTex, Vector2f(700, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 123:
	{
		Sound[5].playSound(50);
		setLaser(bullets, BulletTex, Vector2f(300, -15), BulletLaser1);
		setLaser(bullets, BulletTex, Vector2f(700, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 125:
	{
		setLaser(bullets, BulletTex, Vector2f(300, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 127:
	{
		setLaser(bullets, BulletTex, Vector2f(300, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 129:
	{
		Sound[5].playSound(50);
		setLaser(bullets, BulletTex, Vector2f(300, -15), BulletLaser1);
		setLaser(bullets, BulletTex, Vector2f(500, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 131:
	{
		setLaser(bullets, BulletTex, Vector2f(500, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 133:
	{
		setLaser(bullets, BulletTex, Vector2f(500, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 135:
	{
		Sound[5].playSound(50);
		setLaser(bullets, BulletTex, Vector2f(400, -15), BulletLaser1);
		setLaser(bullets, BulletTex, Vector2f(500, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 137:
	{
		setLaser(bullets, BulletTex, Vector2f(400, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 139:
	{
		setLaser(bullets, BulletTex, Vector2f(400, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 141:
	{
		setLaser(bullets, BulletTex, Vector2f(400, -15), BulletLaser1);
		stagePhase++;
		break;
	}
	case 142:
	{
		if (bullets.size() == 0)
		{
			stagePhase++;
			break;
		}
	}
	case 143:
	{
		enemies.push_back(Enemy(30, enemy1Texture, RectEnemy41, RectEnemy42, RectEnemy43, RectEnemy44, Vector2f(100, -15), 270, 0.07, time, 0, 99, 0.06));
		enemies.push_back(Enemy(30, enemy1Texture, RectEnemy41, RectEnemy42, RectEnemy43, RectEnemy44, Vector2f(700, -15), 270, 0.07, time, 0, 99, 0.06));
		enemies.push_back(Enemy(30, enemy1Texture, RectEnemy41, RectEnemy42, RectEnemy43, RectEnemy44, Vector2f(400, -15), 270, 0.07, time, 0, 99, 0.06));
		stagePhase = 145;
		break;
	}
	case 151:
	{
		if (enemies.size() > 0)
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (time - enemies[i].SpecialTimer > 0.3 && bullets.size() < 300)
				{
					Sound[2].playSound(25);
					bulletsHell2(bullets, BulletTex, Vector2f(enemies[i].pos.x + 7, enemies[i].pos.y + 10), 0.15, 4, 270 + enemies[i].bulletUsed * 30 - 22, 270 + enemies[i].bulletUsed * 30 + 22, BulletRedKnife);
					enemies[i].speed = 0;
					enemies[i].bulletUsed++;
				}
			}
		}
		else if (bullets.size() == 0)
		{
			stagePhase++;
		}
		break;
	}
	case 155:
	{
		enemies.push_back(Enemy(20, enemy1Texture, RectEnemyBook, RectEnemyBook, RectEnemyBook, RectEnemyBook, Vector2f(100, 150), 270, 0, time, 0, 99, 0.06));
		stagePhase++;
		break;
	}
	case 156:
	{
		enemies.push_back(Enemy(20, enemy1Texture, RectEnemyBook, RectEnemyBook, RectEnemyBook, RectEnemyBook, Vector2f(300, 50), 270, 0, time, 0, 99, 0.06));
		stagePhase++;
		break;
	}
	case 157:
	{
		enemies.push_back(Enemy(20, enemy1Texture, RectEnemyBook, RectEnemyBook, RectEnemyBook, RectEnemyBook, Vector2f(500, 50), 270, 0, time, 0, 99, 0.06));
		stagePhase++;
		break;
	}
	case 158:
	{
		enemies.push_back(Enemy(20, enemy1Texture, RectEnemyBook, RectEnemyBook, RectEnemyBook, RectEnemyBook, Vector2f(700, 150), 270, 0, time, 0, 99, 0.06));
		stagePhase++;
		break;
	}

	case 160:
	{
		if (enemies.size() > 0)
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (time - enemies[i].SpecialTimer > 1 && bullets.size() < 300)
				{
					
					Sound[4].playSound(25);
					switch ((enemies[i].bulletUsed + i) % 4)
					{
					case 0:
					{
						bulletsHell1withSprite(bullets, BulletTex, Vector2f(enemies[i].pos.x + 7, enemies[i].pos.y + 10), 0.1, 18, BulletLightBlue);
						break;
					}
					case 1:
					{
						bulletsHell1withSprite(bullets, BulletTex, Vector2f(enemies[i].pos.x + 7, enemies[i].pos.y + 10), 0.1, 18, BulletYellow);
						break;
					}
					case 2:
					{
						bulletsHell1withSprite(bullets, BulletTex, Vector2f(enemies[i].pos.x + 7, enemies[i].pos.y + 10), 0.1, 18, Bullet1);
						break;
					}
					case 3:
					{
						bulletsHell1withSprite(bullets, BulletTex, Vector2f(enemies[i].pos.x + 7, enemies[i].pos.y + 10), 0.1, 18, BulletViolet);
						break;
					}
					}
					enemies[i].bulletUsed++;
					enemies[i].SpecialTimer = time;
				}
			}
		}
		else if (bullets.size() == 0)
		{
			stagePhase++;
		}
		break;
	}
	case 161:
	{
		stageBoss = 1;
		stagePhase = 0;
		break;
	}

	default:
	{
		stagePhase++;
		break;
	}
	}
}
void Stage2Boss(std::vector<Bullet> &bullets, Texture *BulletTex, std::vector<Boss> &bosses, Texture *Boss1Texture, float time, std::vector<SoundEffect> &Sound, std::vector<Enemy> &enemies, Texture *enemy1Texture)
{
	switch (stagePhase)
	{
	case 25:
	{
		bosses[0].speed = 0;
		stagePhase++;
		break;
	}
	case 26:
	{
		Sound[5].playSound(50);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 12, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 150, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 150, bosses[0].pos.y + 25), BulletLaser1);

		stagePhase++;
		break;
	}
	case 36:
	{
		Sound[5].playSound(50);
		laserLine(bullets, BulletTex, Vector2f(100, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(700, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(300, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(500, bosses[0].pos.y + 25), BulletLaser1);
		stagePhase++;
		break;
	}

	case 46:
	{
		
		Sound[5].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.1, 36, Bullet1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 12, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(200, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(600, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(50, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(750, bosses[0].pos.y + 25), BulletLaser1);
		stagePhase++;
		break;
	}
	case 56:
	{
		
		Sound[5].playSound(50);

		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 12, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 150, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 150, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(25, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(785, bosses[0].pos.y + 25), BulletLaser1);

		stagePhase++;
		break;
	}
	case 80:
	{
		
		if (bosses[0].getHP() > 520)
		{
			stagePhase = 26;
			bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x +15, bosses[0].pos.y + 25), 0.3, 17, BulletBlue);
		}
		else
		{
			stagePhase++;
		}
		break;
	}
	case 81:
	{
		bosses[0].moving = 2;
		bosses[0].angle = 200;
		bosses[0].speed = 0.05;
		stagePhase++;
		break;
	}
	case 96:
	{
		bosses[0].moving = 0;
		bosses[0].angle = 0;
		bosses[0].speed = 0;
		stagePhase++;
		break;
	}
	case 98:
	{
		Sound[10].playSound(70);
		bosses[0].specialAtackBg = 1;
		stagePhase++;
		break;
	}
	case 100:
	{
		bosses[0].moving = 1;
		stagePhase++;
		break;
	}
	case 101:
	{
		bosses[0].pos.x = rand() % 700 + 50;
		bosses[0].pos.y = rand() % 150 + 50;
		Sound[4].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.06, 8, BulletViolet);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.07, 6, Bullet1);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, BulletLightBlue);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.09, 8, BulletBlue);
		stagePhase++;
		break;
	}
	case 106:
	{
		bosses[0].pos.x = rand()%700+50;
		bosses[0].pos.y = rand() % 150 + 50;
		Sound[4].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.06, 8, BulletViolet);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.07, 6, Bullet1);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, BulletLightBlue);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.09, 8, BulletBlue);
		stagePhase++;
		break;
	}
	case 112:
	{
		bosses[0].pos.x = rand() % 700 + 50;
		bosses[0].pos.y = rand() % 150 + 50;
		Sound[4].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.06, 8, BulletViolet);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.07, 6, Bullet1);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, BulletLightBlue);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.09, 8, BulletBlue);
		stagePhase++;
		break;
	}
	case 117:
	{
		bosses[0].pos.x = rand() % 700 + 50;
		bosses[0].pos.y = rand() % 150 + 50;
		Sound[4].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.06, 8, BulletViolet);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.07, 6, Bullet1);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, BulletLightBlue);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.09, 8, BulletBlue);
		stagePhase++;
		break;
	}
	case 122:
	{
		bosses[0].pos.x = 380;
		bosses[0].pos.y = 100;
		Sound[4].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.06, 8, BulletViolet);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.07, 6, Bullet1);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, BulletLightBlue);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.09, 8, BulletBlue);
		stagePhase++;
		break;
	}
	case 142:
	{

		if (bosses[0].getHP() > 400)
		{
			
			stagePhase = 101;
			
		}
		else
		{
			while (bullets.size())
			{
				bullets.erase(bullets.begin());
			}
			Sound[11].playSound(80);
			bosses[0].specialAtackBg = 0;
			bosses[0].moving = 0;
			stagePhase++;
		}
		break;
	}
	case 151:
	{
		enemies.push_back(Enemy(20, enemy1Texture, RectEnemyBook, RectEnemyBook, RectEnemyBook, RectEnemyBook, Vector2f(600, 80), 270, 0, time, 0, 99, 0.06));
		enemies.push_back(Enemy(20, enemy1Texture, RectEnemyBook, RectEnemyBook, RectEnemyBook, RectEnemyBook, Vector2f(200, 80), 270, 0, time, 0, 99, 0.06));
		stagePhase++;
		break;
	}
	case 153:
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			if (time - enemies[i].SpecialTimer > 0.15 && bullets.size() < 300)
			{
				Sound[2].playSound(25);
				bulletsHell2(bullets, BulletTex, Vector2f(enemies[i].pos.x + 7, enemies[i].pos.y + 10), 0.15, 4, 270 + enemies[i].bulletUsed * 30 - 22, 270 + enemies[i].bulletUsed * 30 + 22, BulletIceShard);
				enemies[i].bulletUsed++;
				enemies[i].SpecialTimer = time;
			}
		}
		if (time - bosses[0].SpecialTimer > 2.5 && bullets.size() < 300)
		{
			Sound[3].playSound(50);
			for (int i = 0; i < 20; i++)
			{
				bullets.push_back(Bullet(BulletTex, BulletRedKnife, Vector2f(bosses[0].pos.x + 9, bosses[0].pos.y + 25), getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos), 0.17 + (float)i / 100));
				bullets.back().shape.rotate(270 - getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos));
			}
			bosses[0].SpecialTimer = time;
		}
	}
	case 154:
	{
		if (bosses[0].getHP() > 300)
		{

			stagePhase = 153;

		}
		else
		{
			while (enemies.size())
			{
				enemies.erase(enemies.begin());
			}
			
			stagePhase++;
		}
		break;
	}
	case 156:
	{
		bosses[0].moving = 2;
		bosses[0].angle = 0;
		bosses[0].speed = 0.04;
		stagePhase++;
		break;
	}
	case 160:
	{
		Sound[3].playSound(30);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.1, 7, getNewAngle(bosses[0].pos, PlayerPos) - 45, getNewAngle(bosses[0].pos, PlayerPos) + 45, BulletBlue);
		stagePhase++;
		break;
	}
	case 161:
	{
		if (bosses[0].pos.x > 600)
		{
			stagePhase++;
		}
		else
		{
			stagePhase = 156;
		}
		if (bosses[0].getHP() < 250) stagePhase = 168;
		break;
	}
	case 162:
	{
		bosses[0].moving = 2;
		bosses[0].angle = 180;
		bosses[0].speed = 0.04;
		stagePhase++;
		break;
	}
	case 166:
	{
		Sound[3].playSound(30);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.1, 7, getNewAngle(bosses[0].pos, PlayerPos) - 45, getNewAngle(bosses[0].pos, PlayerPos) + 45, BulletBlue);
		stagePhase++;
		break;
	}
	case 167:
	{
		if (bosses[0].pos.x < 100)
		{
			stagePhase = 156;
		}
		else
		{
			stagePhase = 162;
		}
		if (bosses[0].getHP() < 250) stagePhase = 168;
		break;
	}
	case 168:
	{
		bosses[0].speed = 0;
		bosses[0].angle = 0;
		bosses[0].moving = 0;
		bosses[0].pos.x = 380;
		bosses[0].pos.y = 70;
		stagePhase++;
		break;
	}
	case 169:
	{
		bosses[0].moving = 1;
		Sound[10].playSound(70);
		bosses[0].specialAtackBg = 1;
		stagePhase++;
		while (bullets.size())
		{
			bullets.erase(bullets.begin());
		}
		break;
	}
	case 179:
	{
		bosses[0].pos.x = 780;
		bosses[0].pos.y = 50;
		Sound[3].playSound(45);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, 180, 270, BulletIceShard);
		stagePhase++;
		break;
	}
	case 180:
	{
		bosses[0].pos.x = 20;
		bosses[0].pos.y = 50;
		Sound[3].playSound(45);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, 270 , 360, BulletIceShard);
		stagePhase++;
		break;
	}
	case 181:
	{
		bosses[0].pos.x = 20;
		bosses[0].pos.y = 540;
		Sound[3].playSound(45);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, 0, 90, BulletIceShard);
		stagePhase++;
		break;
	}
	case 182:
	{
		bosses[0].pos.x = 780;
		bosses[0].pos.y = 540;
		Sound[3].playSound(45);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.08, 7, 90, 180, BulletIceShard);
		stagePhase++;
		break;
	}
	case 183:
	{
		bosses[0].pos.x = 300;
		bosses[0].pos.y = 200;
		Sound[2].playSound(55);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.05, 7, BulletYellow);
		stagePhase++;
		break;
	}
	case 188:
	{
		bosses[0].pos.x = 500;
		bosses[0].pos.y = 200;
		Sound[2].playSound(55);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.05, 7, BulletYellow);
		stagePhase++;
		break;
	}
	case 193:
	{
		bosses[0].pos.x = 380;
		bosses[0].pos.y = 75;
		Sound[2].playSound(55);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.05, 26, BulletYellow);
		stagePhase++;
		break;
	}

	case 205:
	{
		if (bosses[0].getHP() < 145)
		{
			while (bullets.size())
			{
				bullets.erase(bullets.begin());
			}
			Sound[11].playSound(80);
			bosses[0].specialAtackBg = 0;
			bosses[0].moving = 0;
			stagePhase++;
		}
		else  stagePhase = 179;
		break;
	}
	case 215:
	{
		Sound[5].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.15, 7, Bullet1);

		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 4, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 154, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 150, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(25, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(785, bosses[0].pos.y + 25), BulletLaser1);
		stagePhase++;
		break;
	}
	case 220:
	{
		Sound[5].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.2, 8, Bullet1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 30, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 30, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 60, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 60, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 300, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 300, bosses[0].pos.y + 25), BulletLaser1);

		stagePhase++;
		break;
	}
	case 225:
	{
		Sound[5].playSound(50);
		bulletsHell1withSprite(bullets, BulletTex, Vector2f(bosses[0].pos.x + 15, bosses[0].pos.y + 25), 0.3, 9, Bullet1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x , bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 150, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 150, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 350, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 250, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 250, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 350, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x + 70, bosses[0].pos.y + 25), BulletLaser1);
		laserLine(bullets, BulletTex, Vector2f(bosses[0].pos.x - 70, bosses[0].pos.y + 25), BulletLaser1);
		stagePhase++;
		break;
	}
	case 250:
	{
		bosses[0].moving = 1;
		Sound[10].playSound(70);
		bosses[0].specialAtackBg = 1;
		stagePhase++;
		while (bullets.size())
		{
			bullets.erase(bullets.begin());
		}
		break;
	}
	case 251:
	{
		bosses[0].speed = 0.05;
		bosses[0].angle = 200;
		stagePhase++;
		break;
	}
	case 256:
	{
	
		Sound[4].playSound(35);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.15, 6, getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos) + 60, getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos) - 60, BulletViolet);
		stagePhase++;
		break;
	}
	case 261:
	{
		Sound[5].playSound(50);
		Vector2f bullpos(rand() % 700 + 50, rand() % 100 + 5);
		bulletsHell1withSprite(bullets, BulletTex, bullpos, 0.18, 5, BulletBlue);
		laserLine(bullets, BulletTex, bullpos, BulletLaser1);
		stagePhase++;
		break;

	}
	case 266:
	{
		if (bosses[0].pos.x < 150)
		{
			bosses[0].pos.y = 80;
			bosses[0].pos.x = 380;
			bosses[0].speed = 0.05;
			bosses[0].angle = 340;
			stagePhase++;
			bulletsHell1withSprite(bullets, BulletTex, Vector2f(-10, 300) , 0.22, 18, Bullet1);
			for (int i = 0; i < 40; i++)
			{
				Sound[2].playSound(55);
				bullets.push_back(Bullet(BulletTex, BulletIceShard, Vector2f(rand() % 780 + 10, -15), 270, (0.1 + (rand() % 10) / 125.0)));
			}
		}
		else
		{
			stagePhase = 256;
		}
	}
	case 267:
	{
		Sound[4].playSound(35);
		bulletsHell2(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.15, 6, getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos) + 60, getNewAngle(Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), PlayerPos) - 60, BulletViolet);
		stagePhase++;
		break;
	}
	case 272:
	{
		Sound[5].playSound(50);
		Vector2f bullpos(rand() % 700 + 50, rand() % 100 + 5);
		bulletsHell1withSprite(bullets, BulletTex, bullpos, 0.18, 5, BulletBlue);
		laserLine(bullets, BulletTex, bullpos, BulletLaser1);
		stagePhase++;
		break;

	}
	case 277:
	{
		if (bosses[0].pos.x > 650)
		{
			bosses[0].pos.y = 80;
			bosses[0].pos.x = 380;
			bosses[0].speed = 0.05;
			bosses[0].angle = 200;
			stagePhase = 256;
			bulletsHell1withSprite(bullets, BulletTex, Vector2f(800, 300), 0.22, 18, Bullet1);
			for (int i = 0; i < 40; i++)
			{
				Sound[2].playSound(55);
				bullets.push_back(Bullet(BulletTex, BulletIceShard, Vector2f(rand() % 780 + 10, -15), 270, (0.1 + (rand() % 10) / 125.0)));
			}
		}
		else
		{
			stagePhase = 267;
		}
		break;
	}

	
	
	default:
	{
		stagePhase++;
		break;
	}
	}
}