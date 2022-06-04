// Pre2Hou.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Objects.hpp"
#include "bulletTrajectoryCalculation.hpp"
#include "Stage1.hpp"
#include "Stage2.hpp"
#include "SoundEffects.hpp"

using namespace sf;


//GLOBAL VARIABLES------------------------------

std::vector <Enemy> enemies;

std::vector <Bullet> bullets;
std::vector <Item> items;
std::vector <ObHpBar> hpBarVector;
std::vector <Boss> bosses;

Vector2f PlayerPos(400.f, 500.f);

//variables used for determining the timeline of 
int enemyCounter = 10; 
int stagePhase = 0;
int stageBoss = 0;

bool DEBUGMODE = 0;
Clock debug_clock;

int test = 35; // not sure if still used

int main()
{
	//Random -----------------------------------------------
	PlayerPos.x = 400.f;
	PlayerPos.y = 500.f;
	Texture stage1BackgroundText;
	stage1BackgroundText.loadFromFile("img/bg2.jpg");
	Sprite stage1Bg;
	stage1BackgroundText.setRepeated(true);
	stage1BackgroundText.setSmooth(true);

	Texture stage2BackgroundText;
	stage2BackgroundText.loadFromFile("img/LibraryBg.png");
	Sprite stage2Bg;
	stage2BackgroundText.setRepeated(true);
	stage2BackgroundText.setSmooth(true);
	stage2Bg.setTexture(stage2BackgroundText);

	IntRect stage1bgRect(0, 0, 800, 600);
	stage1Bg.setTexture(stage1BackgroundText);
	int bg1Y = 600;
	stage1Bg.setTextureRect(IntRect(200, bg1Y, 800, 600));

	Texture stage2BossText;
	stage2BossText.loadFromFile("img/Boss2bg.png");
	Sprite stage2BossBg;
	stage2BossText.setRepeated(true);
	stage2BossText.setSmooth(true);
	stage2BossBg.setTexture(stage2BossText);
	int bg2Y = 600;
	stage2BossBg.setTextureRect(IntRect(0, bg2Y, 800, 600));

	Clock bgClock; //clock for moving background
	bool bgstop = 0;

	//Init text
	Font font;
	font.loadFromFile("fonts/Font2.ttf");

	Font titleFont;
	titleFont.loadFromFile("fonts/Font1.otf");
	srand(time(NULL));
	Clock enemyClock;
	int movingClock = 0;

	//textures init -------------------------------
	Texture BossesText;
	BossesText.loadFromFile("img/Bosses2.png");
	Texture enemy1Texture;
	enemy1Texture.loadFromFile("img/Enemies2.png");
	Texture PlayerTex;
	PlayerTex.loadFromFile("img/Reimu2.png");
	Texture BulletTex;
	BulletTex.loadFromFile("img/Bullets2.png");
	Texture TitleTex;
	TitleTex.loadFromFile("img/TitleScreen.png");
	Sprite titleSprite;
	titleSprite.setTexture(TitleTex);
	float titleY = -600; // used for moving background
	titleSprite.setPosition(0, titleY);

	Texture EndingTex;
	EndingTex.loadFromFile("img/ScarletMansion.jpg");
	Sprite endSprite;
	endSprite.setTexture(EndingTex);
	endSprite.setScale(Vector2f(1.7, 1.5));

	Texture staffRollTex;
	staffRollTex.loadFromFile("img/end.jpg");
	Sprite staffSprite;
	staffSprite.setTexture(staffRollTex);
	staffSprite.setScale(Vector2f(2.67, 2.67));


	//CREATING WINDOW -----------------------------------------------------------------------
	RenderWindow Window(sf::VideoMode(800, 600), "EOSD 0.1", Style::Titlebar | Style::Close);
	bool isFullscreen = false;
	Clock fullscreenClock;

	//PLAYER ----------- Variables and init -------------------------
	Player player(10, &PlayerTex, Player11, Player12, Player13, Player14, Player21, Player22, Player23, Player24, Player31, Player32, Player33, Player34, PlayerPos, playerHitBoxRect, playerBulletRect);
	int Moved = 0; //0 for still, 1 for moving left, 2 for moving right
	int getHPscore = 2;
	Clock invClock;
	float ShiftPressed = 0; //for slower movement


	//SOUND EFFECTS--------------------------------------------------
	SoundBuffer attackSoundBuffer;
	attackSoundBuffer.loadFromFile("sounds/plst00.wav");
	Sound attackSound;
	attackSound.setBuffer(attackSoundBuffer);
	attackSound.setVolume(50.f);
	SoundBuffer getHitSoundBuffer;
	getHitSoundBuffer.loadFromFile("sounds/pldead00.wav");
	Sound getHitSound;
	getHitSound.setBuffer(getHitSoundBuffer);
	getHitSound.setVolume(45.f);
	SoundBuffer damagedEnemySoundBuffer;
	damagedEnemySoundBuffer.loadFromFile("sounds/damage00.wav");
	Sound damagedEnemySound;
	damagedEnemySound.setBuffer(damagedEnemySoundBuffer);
	damagedEnemySound.setVolume(30.f);
	SoundBuffer killedEnemySoundBuffor;
	killedEnemySoundBuffor.loadFromFile("sounds/enep00.wav");
	Sound killedEnemySound;
	killedEnemySound.setBuffer(killedEnemySoundBuffor);
	killedEnemySound.setVolume(35.f);
	SoundBuffer getItemSoundBuffer;
	getItemSoundBuffer.loadFromFile("sounds/item00.wav");
	Sound getItemSound;
	getItemSound.setBuffer(getItemSoundBuffer);
	getItemSound.setVolume(40.f);
	SoundBuffer getHpSoundBuffer;
	getHpSoundBuffer.loadFromFile("sounds/extend.wav");
	Sound getHpSound;
	getHpSound.setBuffer(getHpSoundBuffer);
	getHpSound.setVolume(40.f);
	SoundBuffer grazeSoundBuffer;
	grazeSoundBuffer.loadFromFile("sounds/graze.wav");
	Sound grazeSound;
	grazeSound.setBuffer(grazeSoundBuffer);
	grazeSound.setVolume(40.f);
	SoundBuffer powerUpSoundBuffer;
	powerUpSoundBuffer.loadFromFile("sounds/powerup.wav");
	Sound powerUpSound;
	powerUpSound.setBuffer(powerUpSoundBuffer);
	powerUpSound.setVolume(40.f);
	std::vector <SoundEffect> Sounds;
	Sounds.push_back(SoundEffect("sounds/power0.wav")); //0
	Sounds.push_back(SoundEffect("sounds/power1.wav"));//1
	Sounds.push_back(SoundEffect("sounds/tan00.wav"));//2
	Sounds.push_back(SoundEffect("sounds/tan01.wav"));//3
	Sounds.push_back(SoundEffect("sounds/tan02.wav"));//4
	Sounds.push_back(SoundEffect("sounds/lazer00.wav"));//5
	Sounds.push_back(SoundEffect("sounds/lazer01.wav"));//6
	Sounds.push_back(SoundEffect("sounds/enep01.wav"));//7
	Sounds.push_back(SoundEffect("sounds/select00.wav"));//8
	Sounds.push_back(SoundEffect("sounds/ok00.wav"));//9
	Sounds.push_back(SoundEffect("sounds/cat00.wav"));//10
	Sounds.push_back(SoundEffect("sounds/enep00.wav"));//11
	//end of initializing sounds



	
	

	//TEXTS ---------------------------------------------
	bool isDialogue = 0;
	Text DialogueText;
	DialogueText.setFont(font);
	DialogueText.setCharacterSize(22);
	DialogueText.setFillColor(Color::White);
	DialogueText.setPosition(10, 400);


	Text enemyText;
	enemyText.setFont(font);
	enemyText.setCharacterSize(25);
	enemyText.setFillColor(Color::Yellow);
	enemyText.setPosition(20, 2);

	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(30);
	hpText.setFillColor(Color::White);
	hpText.setPosition(700, 565);

	Text charText;
	charText.setFont(font);
	charText.setCharacterSize(15);
	charText.setFillColor(Color::White);
	charText.setPosition(700, 525);

	Text GameOverText;
	GameOverText.setFont(font);
	GameOverText.setCharacterSize(40);
	GameOverText.setFillColor(Color::Red);
	GameOverText.setPosition(174, 250);
	GameOverText.setString("          Game Over \n Press x to start again");

	Text EndingText;
	EndingText.setFont(font);
	EndingText.setCharacterSize(35);
	EndingText.setFillColor(Color::White);
	EndingText.setPosition(10, 550);
	EndingText.setString("After the battle Patchouli seemed satisfied.");

	Text AfterGameText;
	AfterGameText.setFont(font);
	AfterGameText.setCharacterSize(25);
	AfterGameText.setFillColor(Color::White);
	AfterGameText.setPosition(330, 500);

	bool stageClear = 0;
	Text stageClearTx;
	stageClearTx.setFont(font);
	stageClearTx.setCharacterSize(25);
	stageClearTx.setFillColor(Color::White);
	stageClearTx.setPosition(330, 500);
	

	//Stages variables
	Clock stageClock; // used for the enemies and bosses appearing
	bool stage1 = 0;
	bool stage2 = 0;
	bool ending = 0;

	//Title screen options & texts
	bool titleScreen = 1;
	int titleOpt = 0;
	Text titleOptText1;
	titleOptText1.setFont(titleFont);
	titleOptText1.setString("Play");
	titleOptText1.setCharacterSize(50);
	titleOptText1.setFillColor(Color::Black);
	titleOptText1.setPosition(200, 500);

	Text titleOptText2;
	titleOptText2.setFont(titleFont);
	titleOptText2.setString("Quit");
	titleOptText2.setCharacterSize(25);
	titleOptText2.setFillColor(Color::Blue);
	titleOptText2.setPosition(550, 500);

	//Stage Background Music init ----------------------------------------

	Music stage1Music;
	stage1Music.openFromFile("music/Stage1.wav");
	Music stage1BossMusic;
	stage1BossMusic.openFromFile("music/Stage1Boss.wav");
	Music TitleMusic;
	TitleMusic.openFromFile("music/Title.wav");
	Music stage2Music;
	stage2Music.openFromFile("music/Stage2.wav");
	stage2Music.setLoop(true);
	Music stage2BossMusic;
	stage2BossMusic.openFromFile("music/Stage2Boss.wav");
	stage2BossMusic.setLoop(true);
	Music EndMusic;
	EndMusic.openFromFile("music/Ending.wav");
	EndMusic.setLoop(true);
	Music staffRollMusic;
	staffRollMusic.openFromFile("music/staffRoll.wav");
	staffRollMusic.setLoop(true);
	Text stageText;
	stageText.setFont(font);
	stageText.setCharacterSize(30);
	stageText.setFillColor(Color::White);
	
	bool cutscene = 1; //used for displaying text e.g. "Stage 1"


	//GAME CLOCK
	Clock clock; 
	int FrameCounter = 0; //something like FPS 
	

	//MAIN LOOP ------------------------------------------------//
	//----------------------------------------------------------//
	while (Window.isOpen()) {
		int hp = player.getHP();
		if (hp > 0)
		{


			Window.clear();

				if (titleScreen == 0 && ending == 0) // to prevent from moving you character, when titlescreen or ending sequnce is playing
				{
					if (Keyboard::isKeyPressed(Keyboard::LShift))
					{
						ShiftPressed = 0.25;
					}
					else
					{
						ShiftPressed = 0;
					}
					//controls with window collision
					if (Keyboard::isKeyPressed(Keyboard::Up) && PlayerPos.y > 0)
					{
						PlayerPos.y -= 0.4 - ShiftPressed;
					}
					if (Keyboard::isKeyPressed(Keyboard::Down) && PlayerPos.y <= 600 - 52) //substracted by size of character
					{
						PlayerPos.y += 0.4 - ShiftPressed;
					}
					if (Keyboard::isKeyPressed(Keyboard::Left) && PlayerPos.x > 0)
					{
						Moved = 1;
						PlayerPos.x -= 0.4 - ShiftPressed;

					}
					if (Keyboard::isKeyPressed(Keyboard::Right) && PlayerPos.x <= 800 - 32) //substracted by size of character 
					{
						Moved = 2;
						PlayerPos.x += 0.4 - ShiftPressed;
					}
					if (player.shootenable >= 5 && Keyboard::isKeyPressed(Keyboard::Z)) // shooting bullets by player
					{
						attackSound.play();
						if (player.power >= 50)
						{
							player.bullets.push_back(Bullet(&PlayerTex, playerBulletRect, Vector2f(PlayerPos.x + 31, PlayerPos.y + 23), 90, 0.7 + player.power / 100));
							player.bullets.push_back(Bullet(&PlayerTex, playerBulletRect, Vector2f(PlayerPos.x - 9, PlayerPos.y + 23), 90, 0.7 + player.power / 100));
							player.bullets.push_back(Bullet(&PlayerTex, playerBulletRect, Vector2f(PlayerPos.x + 11, PlayerPos.y + 3), 90, 0.7 + player.power / 100));
						}
						else if (player.power >= 25 && player.power < 50)
						{
							player.bullets.push_back(Bullet(&PlayerTex, playerBulletRect, Vector2f(PlayerPos.x + 21, PlayerPos.y + 18), 90, 0.6 + player.power / 100));
							player.bullets.push_back(Bullet(&PlayerTex, playerBulletRect, Vector2f(PlayerPos.x + 1, PlayerPos.y + 18), 90, 0.6 + player.power / 100));
						}
						else player.bullets.push_back(Bullet(&PlayerTex, playerBulletRect, Vector2f(PlayerPos.x + 11, PlayerPos.y + 18), 90, 0.7 + player.power / 100));
						player.shootenable = 0;
					}
				}

				//Title Screen sequence-------------------------------------------------------------------------------------------
				if (titleScreen)
				{
					Window.draw(titleSprite);
					if (stagePhase == 2)
					{
						Window.draw(titleOptText1);
						Window.draw(titleOptText2);

					}
					if (bgClock.getElapsedTime().asMilliseconds() > 15 && stagePhase <= 1)
					{
						if (stagePhase == 0)
						{
							TitleMusic.play();
							stagePhase++;

						}
						if (titleY < 0 && stagePhase == 1)
						{
							titleY += 2;
							titleSprite.setPosition(0, titleY);
							if (titleY >= 0) stagePhase++; // when background is fully on screen, continue the title screen sequence
						}
						bgClock.restart();
					}
					if (bgClock.getElapsedTime().asMilliseconds() > 100)
					{
						if (stagePhase == 2)
						{
							if (titleOpt == 0 && Keyboard::isKeyPressed(Keyboard::Right))//changing title options
							{
								titleOptText1.setCharacterSize(25);
								titleOptText2.setCharacterSize(50);
								titleOpt = 1;
								Sounds[8].playSound(50);
								bgClock.restart();

							}
							else if (titleOpt == 1 && Keyboard::isKeyPressed(Keyboard::Left))
							{
								titleOptText1.setCharacterSize(50);
								titleOptText2.setCharacterSize(25);
								titleOpt = 0;
								Sounds[8].playSound(50);
								bgClock.restart();
							}
							if (titleOpt == 1 && Keyboard::isKeyPressed(Keyboard::Z))//exiting the game
							{
								Sounds[9].playSound(50);
								Window.close();
								bgClock.restart();
							}
							if (titleOpt == 0 && Keyboard::isKeyPressed(Keyboard::Z)) //clicking on Play and loading stage1
							{
								Sounds[9].playSound(50);
								titleScreen = 0;
								stage1 = 1;
								ending = 0;
								stagePhase = 125;
								TitleMusic.stop();
								bgClock.restart();
							}
							if (Keyboard::isKeyPressed(Keyboard::Q) && Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::E)) { DEBUGMODE = 1; titleOptText1.setString("Debug"); }//activates debug mode

						}

					}


				}
				//STAGE_1---------------------------------------------------------------
				else if (stage1)
				{


					if (bgClock.getElapsedTime().asMilliseconds() > 15 && bgstop == 0) //to make something resembling FPS
					{

						if (bgstop == 0) //used to stop the bg from moving
						{
							bg1Y--;
							stage1Bg.setTextureRect(IntRect(200, bg1Y, 800, 600));
						}
						if (bg1Y == -1090)
						{
							bg1Y = 600;
						}

						bgClock.restart();
					}

					if (stageClock.getElapsedTime().asSeconds() >= 0.5)
					{

						if (stageBoss == 0)
						{
							if (stagePhase >= 100)
							{
								DialogueText.setString("Reimu: Lately there was an explosion at Scarlet Devil Mansion.\nSome strange fog appeared after that. I need to check it \nand prevent another Scarlet Mist Accident at all cost.");
								isDialogue = true;

							}
							if (stagePhase == 99) isDialogue = false;
							if (stagePhase >= 90)//starting sequence
							{

								if (stagePhase == 125) stage1Music.play();
								stageText.setString("Stage 1");
								stageText.setPosition(350, 260);
								stagePhase--;
								if (stagePhase <= 90) {
									stagePhase = 0;
									cutscene = 0;
								}
							}
							else if (stagePhase < 12)
							{
								Stage1(bullets, &BulletTex, enemies, &enemy1Texture, enemyClock.getElapsedTime().asSeconds());
							}
							else if (enemies.size() == 0 && bullets.size() == 0)
							{

								switch (stagePhase)
								{
								case 12:
								{
									isDialogue = true;
									DialogueText.setString("Reimu: It feels great out tonight.");

									stagePhase++;
									break;
								}
								case 16:
								{
									isDialogue = true;
									DialogueText.setPosition(10, 200);
									DialogueText.setString("Rumia: You're so right. I'm hungry. May I eat you?");
									stagePhase++;
									break;
								}
								case 21:
								{
									isDialogue = true;
									DialogueText.setPosition(10, 400);
									DialogueText.setString("Reimu: And you are? Anyway, you're in my way, you know.");
									stagePhase++;
									break;
								}
								case 27:
								{
									stageBoss = 1;
									stagePhase = 999; //this is the starting value of boss in stage 1
									isDialogue = false;
									break;
								}
								default:
								{
									stagePhase++;
									break;
								}
								}
							}

						}
						//STAGE 1 BOSS SEQUENCE
						else if (stageBoss == 1)
						{
							bgstop = 1;
							if (stagePhase > 990)//starting sequence
							{
								stageText.setString("Boss 1 \n Rumia");
								stageText.setPosition(305, 240);
								if (stagePhase == 999)
								{
									stage1Music.stop();
									cutscene = 1;
								}
								stagePhase--;
								if (stagePhase <= 995)
								{
									stagePhase = 990;
									cutscene = 0;
									stage1BossMusic.play();
								}
							}
							if (stagePhase == 990)
							{

								bosses.push_back(Boss(200, &BossesText, RectBoss11, RectBoss12, RectBoss13, Vector2f(400.f, -50.f), 270, 0.05));
								hpBarVector.push_back(ObHpBar(&enemy1Texture, enemyHpBarRect));
								stagePhase = 0;
							}
							if (stagePhase < 990)
							{
								if (bosses.size())
								{
									if (bosses[0].getHP() > 0) Stage1Boss(bullets, &BulletTex, bosses, &BossesText, 0, Sounds);
									else if (bosses[0].getHP() <= 0 && stageClear == 0)
									{

										bosses.erase(bosses.begin());
										Sounds[7].playSound(50);
										stage1BossMusic.stop();
										stageClear = 1;
										player.score += 1000 + player.graze * 10;
										while (bullets.size())
										{
											bullets.erase(bullets.begin());
										}

									}
								}
								if (stageClear)
								{

									if (Keyboard::isKeyPressed(Keyboard::X))
									{
										stageBoss = 0;
										stagePhase = 0;
										stageClear = 0;
										bgstop = 0;
										stage1 = 0;
										stage2 = 1;
										bg1Y = 600;
									}

								}
							}
						}
						stageClock.restart();
					}
					if (bosses.size() > 0)
					{
						if (stageClear == 0 && bosses[0].specialAtackBg == 0) Window.draw(stage1Bg);
					}
					else if (stageClear == 0) Window.draw(stage1Bg);
					if (isDialogue)
					{
						Window.draw(DialogueText);
					}

				}
				//STAGE 2 ------------------------------------------------------------------------
				if (stage2)
				{
					if (stageBoss == 0)
					{
						if (bgClock.getElapsedTime().asMilliseconds() > 15 && bgstop == 0)
						{

							if (bgstop == 0)
							{
								bg1Y--;
								stage2Bg.setTextureRect(IntRect(0, bg1Y, 800, 600));
							}
							if (bg1Y == 0)
							{
								bg1Y = 600;
							}

							bgClock.restart();
						}
						if (stageClock.getElapsedTime().asMilliseconds() > 100)
						{


							if (stagePhase == 0)
							{
								DialogueText.setPosition(10, 400);
								DialogueText.setString("Reimu: Somehow I got to the library of the Scarlet Mansion unnoticed. \nLet's find the source of the problem.");
								stageText.setString("Stage 2");
								stageText.setPosition(350, 260);
								stage2Music.play();
								cutscene = 1;
								isDialogue = true;
							}
							if (stagePhase == 35)
							{
								isDialogue = false;
								cutscene = 0;
							}
							if (stagePhase > 35 && stagePhase < 161)
							{
								Stage2(bullets, &BulletTex, enemies, &enemy1Texture, enemyClock.getElapsedTime().asSeconds(), Sounds);
							}
							else { stagePhase++; }

							if (stagePhase == 175)
							{
								isDialogue = 1;
								DialogueText.setPosition(10, 200);
								DialogueText.setString("Patchouli-The one in red-white over there!\nDon't run amok in my study.");
								stagePhase++;
							}
							if (stagePhase == 210)
							{
								DialogueText.setPosition(10, 400);
								DialogueText.setString("Reimu: Study? (Red-White?)");
								stagePhase++;
							}
							if (stagePhase == 230)
							{
								DialogueText.setPosition(10, 200);
								DialogueText.setString("Patchouli: What are you here for?");
								stagePhase++;
							}
							if (stagePhase == 250)
							{
								DialogueText.setPosition(10, 400);
								DialogueText.setString("Reimu: I'm here to stop the master of this house \nbecause she's releasing too much mist again.");
								stagePhase++;
							}
							if (stagePhase == 280)
							{
								DialogueText.setPosition(10, 200);
								DialogueText.setString("Patchouli: Mist? Oh, you had mistaken my first experiment failure \nfor the second mist incident.");
								stagePhase++;
							}
							if (stagePhase == 310)
							{
								DialogueText.setPosition(10, 400);
								DialogueText.setString("Reimu: So that's it what it was. First.?");
								stagePhase++;
							}
							if (stagePhase == 340)
							{
								DialogueText.setPosition(10, 200);
								DialogueText.setString("Patchouli: Now that you are here I will use you to test the results.");
								stagePhase++;
							}
							if (stagePhase == 370)
							{
								isDialogue = 0;
								stagePhase = 0;
								stageBoss = 1;
							}

							stageClock.restart();

						}
					}
					else
					{
						if (stagePhase == 0)
						{
							bgstop = 1;
							stage2Music.stop();
							stage2BossMusic.play();
							cutscene = 1;
							stageText.setString("Boss 2 \nPatchouli Knowledge");
							stageText.setPosition(270, 240);
							stagePhase++;
						}
						if (stagePhase < 10)
						{
							if (stageClock.getElapsedTime().asSeconds() >= 0.5)
							{
								stagePhase++;
								stageClock.restart();
							}
						}
						if (stagePhase == 10)
						{
							bosses.push_back(Boss(600, &BossesText, RectBoss21, RectBoss22, RectBoss23, Vector2f(400.f, -50.f), 270, 0.05));
							hpBarVector.push_back(ObHpBar(&enemy1Texture, enemyHpBarRect));
							cutscene = 0;
							stagePhase++;
						}
						if (stagePhase > 10)
						{
							if (stageClock.getElapsedTime().asMilliseconds() > 100 && bosses.size())
							{
								if (bosses[0].getHP() > 0)
								{
									Stage2Boss(bullets, &BulletTex, bosses, &BossesText, enemyClock.getElapsedTime().asSeconds(), Sounds, enemies, &enemy1Texture);
								}
								else if (bosses[0].getHP() <= 0 && stageClear == 0)
								{
									while (bullets.size())
									{
										bullets.erase(bullets.begin());
									}
									bosses.erase(bosses.begin());
									Sounds[7].playSound(50);
									stage2BossMusic.stop();
									stageClear = 1;
									player.score += 5000 + player.graze * 10;


								}

								stageClock.restart();
							}
							if (bgClock.getElapsedTime().asMilliseconds() > 7 && bosses.size())
							{
								if (bosses[0].specialAtackBg)
								{
									bg2Y--;
									stage2BossBg.setTextureRect(IntRect(0, bg2Y, 800, 600));
								}
								if (bg2Y == 0)
								{
									bg2Y = 600;
								}

								bgClock.restart();
							}

						}
					}

					if (stageClear)
					{

						if (Keyboard::isKeyPressed(Keyboard::X))
						{
							stageBoss = 0;
							stagePhase = 0;
							stageClear = 0;
							bgstop = 0;
							stage1 = 0;
							stage2 = 0;
							ending = 1;
							bg1Y = 600;
							stageClock.restart();
						}

					}
					if (bosses.size() > 0)
					{
						if (stageClear == 0 && bosses[0].specialAtackBg == 0)
						{
							Window.draw(stage2Bg);
						}
						else
						{
							Window.draw(stage2BossBg);
						}

					}
					else if (stageClear == 0)Window.draw(stage2Bg);

				}
				//ENDING SEQUENCE--------------------------------------------------------------------------------------------------------------
				else if (ending)
				{
					if (stagePhase <= 20)
					{

						Window.draw(endSprite);
					}
					if (stagePhase >= 50)
					{
						Window.draw(staffSprite);
					}
					if (stageClock.getElapsedTime().asSeconds() > 1 && stagePhase <= 20)
					{

						if (stagePhase == 0)
						{
							EndMusic.play();
						}
						if (stagePhase == 5) EndingText.setString("She removed the mist caused by her.");

						if (stagePhase == 10) EndingText.setString("Gensokyo's summer was passing peacefully.");
						if (stagePhase == 15)
						{
							EndingText.setCharacterSize(25);
							EndingText.setString("Like moss covers a stone on a riverside very slowly...");
						}
						if (stagePhase == 20)
						{
							EndingText.setCharacterSize(35);
							EndingText.setString("Hold X to continue.");
						}
						if (stagePhase < 20) stagePhase++;

						if (Keyboard::isKeyPressed(Keyboard::X))
						{
							stagePhase = 50;
							EndMusic.stop();

						}
						stageClock.restart();
					}

					if (stageClock.getElapsedTime().asSeconds() > 1 && stagePhase >= 50)
					{

						if (stagePhase == 50)
						{

							staffRollMusic.play();
							EndingText.setCharacterSize(40);
							EndingText.setPosition(10, 400);
							EndingText.setString("Your score is: " + std::to_string(player.score) + "\nSpectacular");

						}
						if (stagePhase == 55)
						{
							EndingText.setString("CREDITS");
						}
						if (stagePhase == 60)
						{
							EndingText.setString("Programmer: DroneMaker");
						}
						if (stagePhase == 65)
						{
							EndingText.setString("Graphics Designer: ZUN");
						}
						if (stagePhase == 70)
						{
							EndingText.setString("Music Composer: ZUN");
						}
						if (stagePhase == 75)
						{
							EndingText.setString("SPECIAL THANKS");
						}
						if (stagePhase == 80)
						{
							EndingText.setString("to all Test Players");
						}
						if (stagePhase == 85)
						{
							EndingText.setString("and you...");
						}
						if (stagePhase == 100)
						{
							EndingText.setString("Everything is copyrighted to ZUN.\nPress C to quit.");
						}
						stagePhase++;
						stageClock.restart();

					}

					if (stagePhase > 85)
					{
						if (Keyboard::isKeyPressed(Keyboard::C))
						{

							Window.close(); //QUITING THE GAME AFTER ENDING
						}
					}



					Window.draw(EndingText);

				}

				//-GAME-ENGINE-----------------------------------------------------------------------------------------------------------------
				//=============================================================================================================================

				//Frame counter (~60FPS)
				if (clock.getElapsedTime().asMilliseconds() >= 15)
				{
					FrameCounter++;
					player.shootenable++;
					player.CurrentFrame = (FrameCounter / 10) % 4;

					clock.restart();
				}

				//SPRITE INTERACTIONS-----------------------
				//Enemies and player bullets
				for (size_t i = 0; i < player.bullets.size(); i++)
				{

					//Boss collision
					for (size_t k = 0; k < bosses.size(); k++)
					{
						if (player.bullets[i].shape.getGlobalBounds().intersects(bosses[0].shape[bosses[0].moving].getGlobalBounds()))
						{
							bosses[0].setHp(bosses[0].getHP() - 1);
							damagedEnemySound.play();
							player.score += 10 + player.graze / 10;
							if (bosses[0].getHP() == 0)
							{
								items.push_back(Item(&BulletTex, item2Rect, Vector2f(bosses[0].pos.x + 10, bosses[0].pos.y + 12), 2));
							}
							player.bullets.erase(player.bullets.begin() + i);
							break;
						}


					}
					//Enemy collision
					for (size_t k = 0; k < enemies.size(); k++)
					{
						if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape[(FrameCounter / 10) % 4].getGlobalBounds()))
						{

							if (enemies[k].getHP() <= 1)
							{
								player.score += 10 + player.graze / 10;
								killedEnemySound.play();
								rand() % 3 == 0 ? rand() % 10 == 0 ? items.push_back(Item(&BulletTex, item3Rect, Vector2f(enemies[k].pos.x + 6, enemies[k].pos.y + 6), 3)) : items.push_back(Item(&BulletTex, item1Rect, Vector2f(enemies[k].pos.x + 6, enemies[k].pos.y + 6), 1)) : items.push_back(Item(&BulletTex, item0Rect, Vector2f(enemies[k].pos.x + 6, enemies[k].pos.y + 6), 0));
								enemies.erase(enemies.begin() + k);

							}
							else
							{
								enemies[k].setHp(enemies[k].getHP() - 1);
								damagedEnemySound.play();
							}

							player.bullets.erase(player.bullets.begin() + i);
							break;
						}
					}
				}
				//invulnerability after death 
				if (invClock.getElapsedTime().asSeconds() >= 3)
				{
					player.invulnerable = 0;
				}



				//DRAWING SECTION /CALCULATING COLLISIONS AND POSITIONS-----------------------------------------------


				//Displaying Boss
				if (stageBoss)
				{
					for (size_t i = 0; i < bosses.size(); i++)
					{

						bosses[i].pos = getNewPos(bosses[i].pos, bosses[i].angle, bosses[i].speed);
						bosses[i].shape[bosses[i].moving].setPosition(bosses[i].pos);
						Window.draw(bosses[i].shape[bosses[i].moving]);
					}
				}
				//Displaying items
				for (size_t i = 0; i < items.size(); i++)
				{
					items[i].pos = getNewPos(items[i].pos, 270, 0.1);
					items[i].shape.setPosition(items[i].pos);
					if (items[i].shape.getPosition().y > 600)
					{
						items.erase(items.begin() + i);
						break;
					}
					if (items[i].shape.getGlobalBounds().intersects(player.hitBox.getGlobalBounds()))
					{
						switch (items[i].content)
						{
						case 0:
							player.score += 10;
							getItemSound.play();
							break;
						case 1:
							player.power++;
							if (player.power == 25 || player.power == 50) powerUpSound.play();
							else getItemSound.play();
							break;
						case 2:
							player.setHp(player.getHP() + 1);
							getHpSound.play();
							break;
						case 3:
							if ((player.power >= 20 && player.power < 25) || (player.power >= 45 && player.power < 50)) powerUpSound.play();
							else getItemSound.play();
							player.power += 5;
							break;
						default:
							break;
						}
						items.erase(items.begin() + i);
						break;
					}
					Window.draw(items[i].shape);
				}
				//Displaying Enemies and bullets
				for (size_t i = 0; i < enemies.size(); i++)
				{
					enemies[i].pos = getNewPos(enemies[i].pos, enemies[i].angle, enemies[i].speed);
					enemies[i].shape[0].setPosition(enemies[i].pos);
					enemies[i].shape[1].setPosition(enemies[i].pos);
					enemies[i].shape[2].setPosition(enemies[i].pos);
					enemies[i].shape[3].setPosition(enemies[i].pos);
					//erasing enemies outside window
					if (enemies[i].shape[(FrameCounter / 10) % 4].getPosition().y >= 600 || enemies[i].shape[(FrameCounter / 10) % 4].getPosition().x <= 0 - enemies[i].shape[(FrameCounter / 10) % 4].getGlobalBounds().width || enemies[i].shape[(FrameCounter / 10) % 4].getPosition().y <= 0 - enemies[i].shape[(FrameCounter / 10) % 4].getGlobalBounds().height || enemies[i].shape[(FrameCounter / 10) % 4].getPosition().x >= 800)
					{
						enemies.erase(enemies.begin() + i);
						break;
					}
					//enemy and player collision
					if (enemies[i].shape[(FrameCounter / 10) % 4].getGlobalBounds().intersects(player.hitBox.getGlobalBounds()) && player.invulnerable == 0)
					{
						enemies.erase(enemies.begin() + i);
						player.setHp(player.getHP() - 1); // PLAYER TAKE DAMAGE
						getHitSound.play();
						player.power = player.power / 2;
						player.graze = 0;
						PlayerPos.x = 400.f;
						PlayerPos.y = 500.f;
						player.invulnerable = 1;
						invClock.restart();
						break;
					}
					//enemy shooting new bullets
					if (enemies[i].shootenable)
					{
						bullets.push_back(Bullet(&BulletTex, Bullet1, enemies[i].pos, enemies[i].strategy == 0 ? getNewAngle(enemies[i].pos, player.hitBox.getPosition()) : enemies[i].strategy * 10, enemies[i].bulletSpeed));
						enemies[i].shootenable = 0;
						enemies[i].shootTimer = enemyClock.getElapsedTime().asSeconds();

					}
					else if (enemyClock.getElapsedTime().asSeconds() - enemies[i].shootTimer >= enemies[i].shootFrequency)
					{
						enemies[i].shootenable = 1;
					}
					Window.draw(enemies[i].shape[(FrameCounter / 10) % 4]);
				}
				//Displaying enemy bullets
				for (size_t k = 0; k < bullets.size(); k++)
				{
					bullets[k].pos = getNewPos(bullets[k].pos, bullets[k].angle, bullets[k].speed);
					bullets[k].shape.setPosition(bullets[k].pos);
					//erasing bullets outside window 
					if (bullets[k].shape.getPosition().y >= 600 || bullets[k].shape.getPosition().x >= 800 || bullets[k].shape.getPosition().y <= -bullets[k].shape.getGlobalBounds().height || bullets[k].shape.getPosition().x <= -bullets[k].shape.getGlobalBounds().width)
					{
						bullets.erase(bullets.begin() + k);
						break;
					}
					//player and bullet collision
					if (bullets[k].shape.getGlobalBounds().intersects(player.hitBox.getGlobalBounds()) && player.invulnerable == 0)
					{
						player.setHp(player.getHP() - 1); // PLAYER TAKE DAMAGE
						getHitSound.play();
						player.graze = 0;
						player.power = player.power / 2;
						PlayerPos.x = 400.f;
						PlayerPos.y = 500.f;
						player.invulnerable = 1;
						invClock.restart();

					}
					//Graze - players model and bullet collision 
					if (bullets[k].shape.getGlobalBounds().intersects(player.shape[Moved][player.CurrentFrame].getGlobalBounds()) && bullets[k].grazed)
					{
						player.graze++;
						grazeSound.play();
						bullets[k].grazed = 0;
					}

					Window.draw(bullets[k].shape);
				}
				//Displaying bullets
				for (size_t i = 0; i < player.bullets.size(); i++)
				{
					player.bullets[i].pos = getNewPos(player.bullets[i].pos, player.bullets[i].angle, player.bullets[i].speed);
					player.bullets[i].shape.setPosition(player.bullets[i].pos);
					//erasing bullets outside window
					if (player.bullets[i].shape.getPosition().y <= -player.bullets[i].shape.getGlobalBounds().height)
					{
						player.bullets.erase(player.bullets.begin() + i);
						break;
					}

					Window.draw(player.bullets[i].shape);
				}


				//Displaying Player
				if (titleScreen == 0 && ending == 0)
				{
					if (player.score >= 5000 && getHPscore == 2) //getting hp for 2k points
					{
						getHpSound.play();
						player.setHp(player.getHP() + 1);
						getHPscore = 1;
					}
					if (player.score >= 10000 && getHPscore == 1) //getting hp for 2k points
					{
						getHpSound.play();
						player.setHp(player.getHP() + 1);
						getHPscore = 0;
					}
					hpText.setString("HP: " + std::to_string(player.getHP()));
					charText.setString("Score: " + std::to_string(player.score) + "\nGraze :" + std::to_string(player.graze) + "\nPower :" + std::to_string(player.power));

					player.shape[Moved][player.CurrentFrame].setPosition(PlayerPos);
					player.hitBox.setPosition(PlayerPos.x + 11, PlayerPos.y + 18);

					if (!(player.invulnerable && player.CurrentFrame % 2))
					{
						Window.draw(player.shape[Moved][player.CurrentFrame]);
					}
					if (cutscene)
					{
						Window.draw(stageText);
					}
					if (stageBoss && bosses.size() >= 1 && hpBarVector.size() > 0)
					{
						enemyText.setString("Enemy");
						Window.draw(enemyText);
						int x = bosses[0].getHP() * 35 / bosses[0].getHPmax();

						for (int i = 0; i < x; i++)
						{

							Window.draw(hpBarVector[0].tab[i]);
						}
					}
					Moved = 0;
				}
				if (isDialogue)
				{
					Window.draw(DialogueText);
				}
				if (stageClear)
				{
					stageClearTx.setString("Stage Cleared\nYour score:" + std::to_string(player.score) + "\nPress X to continue");
					Window.draw(stageClearTx);
				}
				else if (ending == 0)
				{
					Window.draw(hpText);
					Window.draw(charText);
				}
				Window.display();

				// exiting game and changing screen style 
				Event event;
				while (Window.pollEvent(event)) {
					if (event.type == Event::Closed)
					{
						//clearing memory before closing the game
						while (bullets.size()) bullets.erase(bullets.begin());
						while (enemies.size()) enemies.erase(enemies.begin());
						while (hpBarVector.size()) hpBarVector.erase(hpBarVector.begin());
						while (bosses.size()) bosses.erase(bosses.begin());
						
			
						Window.close();
						break;
					}

					if (event.type == Event::KeyReleased)
					{
						if (event.key.code == Keyboard::Enter)
						{
							if (fullscreenClock.getElapsedTime().asSeconds() > 1)
							{
								if (isFullscreen)
								{
									Window.create(sf::VideoMode(800, 600), "EOSD 0.1", Style::Titlebar | Style::Close);
									isFullscreen = false;
								}
								else
								{
									Window.create(sf::VideoMode(800, 600), "EOSD 0.1", Style::Fullscreen);
									isFullscreen = true;
								}
								fullscreenClock.restart();
							}
						}
					}

				}
		
		}
		//GameOver sequence ----------------------------------------------------
		else
		{
			Event event;
			while (Window.pollEvent(event)) {
				if (event.type == Event::Closed)
				{
					
					while (bullets.size())
						{
						bullets.erase(bullets.begin());
					}
					while (enemies.size())
					{
						enemies.erase(enemies.begin());
					}
					while (items.size())
					{
						items.erase(items.begin());
					}
					while (bosses.size())
					{
						bosses.erase(bosses.begin());
					}
					Window.close();

				}
				while (bullets.size())
				{
					bullets.erase(bullets.begin());
				}
				while (enemies.size())
				{
					enemies.erase(enemies.begin());
				}
				while (items.size())
				{
					items.erase(items.begin());
				}
				while (bosses.size())
				{
					bosses.erase(bosses.begin());
				}
			}
			
			Window.draw(GameOverText);
			AfterGameText.setString("Score: " + std::to_string(player.score));
			Window.draw(AfterGameText);
			if (Keyboard::isKeyPressed(Keyboard::X))
			{
				stage1Music.stop();
				stage2Music.stop();
				stage1BossMusic.stop();
				stage2BossMusic.stop();
				getHPscore = 2;
				player.score = 0;
				player.graze = 0;
				player.power = 24;
				player.invulnerable = 0;
				player.setHp(player.getHPmax());
				stage1 = 1;
				stage2 = 0;
				stagePhase = 125;
				stageBoss = 0;
				cutscene = 1;
				bgstop = 0;
				DialogueText.setPosition(10, 400);
				
			}
			
			Window.display();

		}
		
		// DEBUG SEQUENCE
		//Anything below this point is optional, but I was kind of bored
		if (DEBUGMODE && debug_clock.getElapsedTime().asSeconds()> 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::F1))
			{
				while (bullets.size()) bullets.erase(bullets.begin());
				while (enemies.size()) enemies.erase(enemies.begin());
				while (bosses.size())  bosses.erase(bosses.begin());
				while (hpBarVector.size()) hpBarVector.erase(hpBarVector.begin());
				EndMusic.stop();
				stage1Music.stop();
				stage2Music.stop();
				stage1BossMusic.stop();
				stage2BossMusic.stop();
				getHPscore = 2;
				player.score = 0;
				player.graze = 0;
				player.power = 49;
				player.invulnerable = 0;
				player.setHp(7);
				stage1 = 1;
				stage2 = 0;
				stagePhase = 125;
				stageBoss = 0;
				cutscene = 1;
				bgstop = 0;
				DialogueText.setPosition(10, 400);
				debug_clock.restart();
			}
			else if (Keyboard::isKeyPressed(Keyboard::F2))
			{
				while (bullets.size()) bullets.erase(bullets.begin());
				while (enemies.size()) enemies.erase(enemies.begin());
				while (bosses.size())  bosses.erase(bosses.begin());
				while (hpBarVector.size()) hpBarVector.erase(hpBarVector.begin());
				EndMusic.stop();
				stage1Music.stop();
				stage2Music.stop();
				stage1BossMusic.stop();
				stage2BossMusic.stop();
				getHPscore = 2;
				player.score = 0;
				player.graze = 0;
				player.power = 50;
				player.invulnerable = 0;
				player.setHp(7);
				stage1 = 1;
				stage2 = 0;
				stagePhase = 999;
				stageBoss = 1;
				cutscene = 1;
				bgstop = 1;
				isDialogue = 0;
				ending = 0;
				titleScreen = 0;
				DialogueText.setPosition(10, 400);
			}
			else if (Keyboard::isKeyPressed(Keyboard::F3))
			{
				while (bullets.size()) bullets.erase(bullets.begin());
				while (enemies.size()) enemies.erase(enemies.begin());
				while (bosses.size())  bosses.erase(bosses.begin());
				while (hpBarVector.size()) hpBarVector.erase(hpBarVector.begin());

				EndMusic.stop();
				stage1Music.stop();
				stage2Music.stop();
				stage1BossMusic.stop();
				stage2BossMusic.stop();
				getHPscore = 2;
				player.score = 0;
				player.graze = 0;
				player.power = 49;
				player.invulnerable = 0;
				player.setHp(7);
				stage1 = 0;
				stage2 = 1;
				stagePhase = 0;
				stageBoss = 0;
				cutscene = 1;
				bgstop = 0;
				ending = 0;
				titleScreen = 0;
				DialogueText.setPosition(10, 400);
				debug_clock.restart();
			}
			else if (Keyboard::isKeyPressed(Keyboard::F4))
			{
				while (bullets.size()) bullets.erase(bullets.begin());
				while (enemies.size()) enemies.erase(enemies.begin());
				while (hpBarVector.size()) hpBarVector.erase(hpBarVector.begin());
				while (bosses.size())  bosses.erase(bosses.begin());
				EndMusic.stop();
				stage1Music.stop();
				stage2Music.stop();
				stage1BossMusic.stop();
				stage2BossMusic.stop();
				getHPscore = 2;
				player.score = 0;
				player.graze = 0;
				player.power = 50;
				player.invulnerable = 0;
				player.setHp(7);
				stage1 = 0;
				stage2 = 1;
				stagePhase = 0;
				stageBoss = 1;
				isDialogue = 0;
				cutscene = 1;
				bgstop = 0;
				ending = 0;
				titleScreen = 0;
				DialogueText.setPosition(10, 400);
				debug_clock.restart();
			}
			else if (Keyboard::isKeyPressed(Keyboard::F5))
			{
			while (bullets.size()) bullets.erase(bullets.begin());
			while (enemies.size()) enemies.erase(enemies.begin());
			while (bosses.size())  bosses.erase(bosses.begin());
			stage1Music.stop();
			stage2Music.stop();
			stage1BossMusic.stop();
			stage2BossMusic.stop();
			EndMusic.stop();
			getHPscore = 2;
			player.score = 0;
			player.graze = 0;
			player.power = 50;
			player.invulnerable = 0;
			player.setHp(7);
			stage1 = 0;
			stage2 = 0;
			stagePhase = 0;
			stageBoss = 0;
			isDialogue = 0;
			cutscene = 1;
			bgstop = 0;
			ending = 1;
			titleScreen = 0;
			DialogueText.setPosition(10, 400);
			debug_clock.restart();
			}
		}
	}
	
}
