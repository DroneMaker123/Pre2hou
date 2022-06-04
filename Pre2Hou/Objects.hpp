#pragma once
using namespace sf;

class Object
{
protected:
	int hp;
	int hpMax;
public:
	int angle;
	float speed;
	int CurrentFrame;
	 Object()
	 {
		 CurrentFrame = 0;
	 }
	~Object(){}
	void setHp(int value) { hp = value; }
	void setHpMax(int value) { hpMax = value; }
	int getHP() { return hp; }
	int getHPmax() { return hpMax; }
};
class Bullet
{	
public:
	Sprite shape;
	int angle;
	float speed;
	Vector2f pos;
	bool grazed;
	Bullet(sf::Texture *texture, IntRect bulletArea, sf::Vector2f pos, int angle, float speed)
	{
		this->grazed = 1;
		this->shape.setTexture(*texture);
		this->shape.setTextureRect(bulletArea);
		this->shape.setPosition(pos);
		this->speed = speed;
		this->angle = angle;
		this->pos = pos;
	}

	~Bullet(){}
};

class Enemy : public Object
{
public:
	Sprite shape[4];
	Vector2f pos;
	int shootenable;
	float shootTimer;
	float shootFrequency;
	int strategy;
	float bulletSpeed;
	float SpecialTimer;
	int bulletUsed;
	Enemy(int health, sf::Texture *texture, sf::IntRect Anim1, sf::IntRect Anim2, sf::IntRect Anim3, sf::IntRect Anim4, sf::Vector2f position, int ang, float speedv, float timer, int strategy, float shootFrequency, float bulletSpeed)
	{
		this->bulletUsed = 0;
		this->SpecialTimer = timer;
		this->bulletSpeed = bulletSpeed;
		this->strategy = strategy;
		this->shootTimer = timer;
		shape[0].setTexture(*texture);
		shape[0].setTextureRect(Anim1);
		shape[1].setTexture(*texture);
		shape[1].setTextureRect(Anim2);
		shape[2].setTexture(*texture);
		shape[2].setTextureRect(Anim3);
		shape[3].setTexture(*texture);
		shape[3].setTextureRect(Anim4);
		this->pos = position;
		this->speed = speedv;
		this->angle = ang;
		setHpMax(health);
		setHp(health);
		this->shootenable = 0;
		this->shootFrequency = shootFrequency;
	}
	~Enemy(){}

};

class Boss : public Object
{
public:
	Sprite shape[3];
	Vector2f pos;
	std::vector<Bullet> bullets;
	int moving; 
	int angle;
	float speed;
	bool specialAtackBg;
	int bulletUsed;
	float SpecialTimer;
	Boss(int health, sf::Texture *texture, sf::IntRect still, sf::IntRect moving1, sf::IntRect moving2, sf::Vector2f pos, int angle, float speed)
	{
		this->SpecialTimer = 0;
		this->bulletUsed = 0;
		this->specialAtackBg = 0;
		this->speed = speed;
		this->angle = angle;
		this->moving = 0;
		shape[0].setTexture(*texture);
		shape[0].setTextureRect(still);
		shape[1].setTexture(*texture);
		shape[1].setTextureRect(moving1);
		shape[2].setTexture(*texture);
		shape[2].setTextureRect(moving2);
		this->pos = pos;
		setHpMax(health);
		setHp(health);
	}
	~Boss() {}

};

class Player : public Object
{
public:
	Sprite shape[3][4];
	Sprite hitBox;
	IntRect bulletArea;
	int shootenable;
	int invulnerable;
	float invTimer;
	int score;
	int power;
	int graze;
	std::vector<Bullet> bullets;
	Player(int health, sf::Texture *texture, sf::IntRect Anim11, sf::IntRect Anim12, sf::IntRect Anim13, sf::IntRect Anim14, sf::IntRect Anim21, sf::IntRect Anim22, sf::IntRect Anim23, sf::IntRect Anim24, sf::IntRect Anim31, sf::IntRect Anim32, sf::IntRect Anim33, sf::IntRect Anim34, sf::Vector2f pos, IntRect playerHitBox, IntRect bulletRect)
	{
		this->score = 0;
		this->graze = 0;
		this->power = 0;
		this->invTimer = 0;
		this->shootenable = 0;
		this->invulnerable = 0;
		hitBox.setTexture(*texture);
		hitBox.setTextureRect(playerHitBox);
		this->bulletArea = bulletRect;
		shape[0][0].setTexture(*texture);
		shape[0][0].setTextureRect(Anim11);
		shape[0][1].setTexture(*texture);
		shape[0][1].setTextureRect(Anim12);
		shape[0][2].setTexture(*texture);
		shape[0][2].setTextureRect(Anim13);
		shape[0][3].setTexture(*texture);
		shape[0][3].setTextureRect(Anim14);

		shape[1][0].setTexture(*texture);
		shape[1][0].setTextureRect(Anim21);
		shape[1][1].setTexture(*texture);
		shape[1][1].setTextureRect(Anim22);
		shape[1][2].setTexture(*texture);
		shape[1][2].setTextureRect(Anim23);
		shape[1][3].setTexture(*texture);
		shape[1][3].setTextureRect(Anim24);

		shape[2][0].setTexture(*texture);
		shape[2][0].setTextureRect(Anim31);
		shape[2][1].setTexture(*texture);
		shape[2][1].setTextureRect(Anim32);
		shape[2][2].setTexture(*texture);
		shape[2][2].setTextureRect(Anim33);
		shape[2][3].setTexture(*texture);
		shape[2][3].setTextureRect(Anim34);
		setHpMax(health);
		setHp(health);
	}
	~Player() {}

};

class ObHpBar
{
public:
	Sprite tab[35];
	Texture tex;
	ObHpBar(sf::Texture *texture, IntRect rect)
	{
		for (int i = 0; i < 35; i++)
		{
			this->tab[i].setTexture(*texture);
			this->tab[i].setTextureRect(rect);
			this->tab[i].rotate(270);
			this->tab[i].setOrigin(0, 0);
			this->tab[i].setPosition(i * 16 + 125, 36);
		}
	}
};

class Item
{
public:
	Sprite shape;
	Vector2f pos;
	int content; //0 - points, 1- power up, 2 - hp, 3- big power up

	Item(sf::Texture *texture, IntRect rectArea, sf::Vector2f pos, int content)
	{
		this->shape.setTexture(*texture);
		this->shape.setTextureRect(rectArea);
		this->shape.setPosition(pos);
		this->pos = pos;
		this->content = content;
	}

	~Item() {}
};
//Rectangles for sprites from SpriteSheet
IntRect RectBoss131(267, 1498, 64, 80);
IntRect RectBoss132(331, 1498, 64, 80);
IntRect RectBoss133(394, 1498, 64, 80); // Boss RemilliaScarlet(100, &Bosses, RectBoss11, RectBoss12, RectBoss13, vector);*/

//Rumia sprites
IntRect RectBoss11(404, 292, 32, 50);
IntRect RectBoss12(436, 292, 32, 50);
IntRect RectBoss13(468, 292, 32, 50);
//Patchouli Knowledge sprites
IntRect RectBoss21(179, 569, 32, 50);
IntRect RectBoss22(211, 569, 32, 50);
IntRect RectBoss23(343, 569, 37, 50);


IntRect RectEnemy11(14, 39, 32, 32);
IntRect RectEnemy12(46, 39, 32, 32);
IntRect RectEnemy13(78, 39, 32, 32);
IntRect RectEnemy14(110, 39, 32, 32);

IntRect RectEnemy21(142, 39, 32, 32);
IntRect RectEnemy22(174, 39, 32, 32);
IntRect RectEnemy23(206, 39, 32, 32);
IntRect RectEnemy24(238, 39, 32, 32);

IntRect RectEnemy31(12, 336, 32, 32);
IntRect RectEnemy32(44, 336, 32, 32);
IntRect RectEnemy33(76, 336, 32, 32);
IntRect RectEnemy34(108, 336, 32, 32);

IntRect RectEnemy41(139, 336, 32, 32);
IntRect RectEnemy42(171, 336, 32, 32);
IntRect RectEnemy43(203, 336, 32, 32);
IntRect RectEnemy44(235, 336, 32, 32);

IntRect RectEnemyBook(176, 433, 26, 29);

IntRect Player11(0, 0, 32, 52);
IntRect Player12(32, 0, 32, 52);
IntRect Player13(64, 0, 32, 52);
IntRect Player14(96, 0, 32, 52);
IntRect Player21(0, 52, 32, 52);
IntRect Player22(32, 52, 32, 52);
IntRect Player23(64, 52, 32, 52);
IntRect Player24(96, 52, 32, 52);
IntRect Player31(0, 104, 32, 52);
IntRect Player32(32, 104, 32, 52);
IntRect Player33(64, 104, 32, 52);
IntRect Player34(96, 104, 32, 52);
IntRect playerHitBoxRect(11, 18, 10, 10);
IntRect playerBulletRect(2, 158, 12, 17);

IntRect Bullet1(348, 62, 16, 16);
IntRect BulletViolet(380, 62, 16, 16);
IntRect BulletYellow(540, 62, 16, 16);
IntRect BulletLightBlue(460, 62, 16, 16);
IntRect BulletBlue(412, 62, 16, 16);

IntRect BulletRedKnife(367, 113, 10, 16);
IntRect BulletIceShard(463, 129, 10, 18);
IntRect BulletBigRedBall(331, 304, 62, 62);

IntRect BulletLaser1(428, 45, 16, 16);

IntRect item1Rect(334, 29, 12, 12);
IntRect item0Rect(350, 29, 12, 12);
IntRect item2Rect(415, 27, 16, 16);
IntRect item3Rect(364, 27, 16, 16);

IntRect enemyHpBarRect(539, 45, 17, 17);