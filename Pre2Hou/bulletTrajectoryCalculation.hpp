#pragma once
#include "pch.h"
#include "Objects.hpp"

#define PI 3.14159265

//Direction of an 0 angle is right
Vector2f getNewPos(Vector2f pos, int angle, float speed) // gets new current position of an object using its current speed and angle of the movement 
{
	Vector2f newPos;
	newPos.x = pos.x + speed*cos(angle*PI / 180);
	newPos.y = pos.y - speed*sin(angle*PI / 180);
	return newPos;
}

int getNewAngle(Vector2f pos1, Vector2f pos2) //gets angle from one point to another
{
	return -(90 - 180*atan2((pos2.x - pos1.x), (pos2.y - pos1.y))/PI); 
}


void bulletsHell1(std::vector<Bullet> &bullet, Texture *BulletTex, Vector2f pos, float speed, int value) //make bullets appear from one point in every directions
{
	for (int i = 0; i < value; i++)
	{
		bullet.push_back(Bullet(BulletTex, Bullet1, pos, i*(360/value) , speed));

	}
}

void bulletsHell2(std::vector<Bullet> &bullet, Texture *BulletTex, Vector2f pos, float speed, int value, int angle1, int angle2, IntRect Rect) 
{
	for (int i = 0; i < value; i++)
	{	
		bullet.push_back(Bullet(BulletTex, Rect, pos, angle1 +(i*(angle2 - angle1) / value), speed));
		bullet.back().shape.rotate(-(angle1 + (i*(angle2 - angle1) / value)+90));
	}
}

void bulletsHell1withSprite(std::vector<Bullet> &bullet, Texture *BulletTex, Vector2f pos, float speed, int value, IntRect Rect) 
{
	for (int i = 0; i < value; i++)
	{
		bullet.push_back(Bullet(BulletTex, Rect, pos, i*360 / value, speed));
		bullet.back().shape.rotate(-(i * 360 / value +90 ));
	}
}

void setLaser(std::vector<Bullet> &bullet, Texture *BulletTex, Vector2f pos, IntRect Rect) //makes something resembling laser
{
	for (int i = 0; i < 10; i++)
	{
		bullet.push_back(Bullet(BulletTex, Rect,Vector2f( pos.x, pos.y + i*16), 270, 0.5));
		bullet.back().shape.setScale(2.f, 1.f);
	}
}

void laserLine(std::vector<Bullet> &bullet, Texture *BulletTex, Vector2f pos, IntRect Rect ) //spawn bullets in straight line
{
	bullet.push_back(Bullet(BulletTex, Rect, Vector2f(pos.x, -15), 270, 0.45));
	bullet.back().shape.setScale(0.7, 18);

}
Vector2f getNewPosSin0(Vector2f pos, float speed, float i) // sinusoidal trajectory (for 0 angle only) [not used]
{
	Vector2f newPos;
	newPos.x = pos.x + speed;
	newPos.y = pos.y + speed * sin(i*PI / 180);
	return newPos;
}
Vector2f getNewPosSin270(Vector2f pos, float speed, float i) // sinusoidal trajectory (for 270 angle only)[not used]
{
	Vector2f newPos;
	newPos.y = pos.y + speed;
	newPos.x = pos.x + speed * sin(i*PI / 180);
	return newPos;
}
Vector2f getNewPosCos0(Vector2f pos, float speed, float i) // Cosinusoidal trajectory (for 0 angle only)[not used]
{
	Vector2f newPos;
	newPos.x = pos.x + speed;
	newPos.y = pos.y + speed * cos(i*PI / 180);
	return newPos;
}
Vector2f getNewPosCos270(Vector2f pos, float speed, float i) // Cosinusoidal trajectory (for 270 angle only)[not used]
{
	Vector2f newPos;
	newPos.y = pos.y + speed;
	newPos.x = pos.x + speed * cos(i*PI / 180);
	return newPos;
}