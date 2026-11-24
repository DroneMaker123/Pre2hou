# Pre2hou

<div align="center">

  **A Touhou-inspired 2D bullet-hell shooter written in C++ with SFML.**

  *Non-commercial fan game. Graphics and music belong to ZUN / Team Shanghai Alice.*

</div>

---

## 📖 About

Pre2hou is a small vertical shoot 'em up made as a C++ learning project, inspired by *Touhou Koumakyou ~ the Embodiment of Scarlet Devil*.

The player controls Reimu through two stages. Each stage has scripted enemy waves, dialogue, and a boss fight with several attack phases. Rumia is the boss of Stage 1, and Patchouli Knowledge is the boss of Stage 2. The game also has a title screen, a short ending sequence and credits.

Gameplay follows genre conventions:

- **Power**: collected items increase player firepower (1 → 2 → 3 parallel shots).
- **Graze**: bullets that brush past the player's sprite (without hitting the small hitbox) raise the score multiplier.
- **Focus movement**: holding Shift slows the player down for precise dodging.
- **Extra lives**: awarded at score thresholds and dropped by bosses.

| Project scale | |
|:---|---:|
| Lines of code (own) | ~3,000 |
| Stages | 2 (+ 2 bosses) |
| Sound effects | 26 |
| Music tracks | 8 |

---

## 🎮 Controls

| Key | Action |
|:---|:---|
| Arrows | Move |
| Left Shift | Slow (focused) movement |
| Z | Shoot / confirm |
| X, C | Continue / quit on stage-clear, game-over and ending screens |
| Enter | Toggle fullscreen |

---

## 🛠️ Technology Stack

| Category | Technology |
|:---|:---|
| Language | C++ |
| Library | SFML (graphics, window, audio) |
| IDE / build | Visual Studio (`Pre2Hou.sln`) |
| Platform | Windows |

---

## 🧱 Architecture

The project is intentionally simple. A single game loop in `Pre2Hou.cpp` works through the game states (title → stage 1 → stage 2 → ending, plus game over). Each frame it updates and draws every entity.

| File | Responsibility |
|:---|:---|
| `Pre2Hou.cpp` | Window, asset loading, main loop, input, collisions, HUD, state transitions |
| `Objects.hpp` | Entity classes (`Object` → `Player`, `Enemy`, `Boss`; `Bullet`, `Item`) and sprite-sheet rectangles |
| `bulletTrajectoryCalculation.hpp` | Movement math and reusable bullet-pattern generators |
| `Stage1.hpp`, `Stage2.hpp` | Stage scripts: enemy waves and boss attack sequences |
| `SoundEffects.hpp` | Small wrapper around `sf::SoundBuffer` / `sf::Sound` |
| `file_manager.*` | Template helper that loads SFML resources and collects missing files |

> The snippets below are taken from the repository. Some lines were left out to keep them short (marked with `// ...`).

### Movement: angle + speed

Every moving object (player bullets, enemy bullets, enemies, bosses, items) stores only an **angle** and a **speed**. One function turns them into the next position, so all movement in the game goes through the same code.

```cpp
// bulletTrajectoryCalculation.hpp
// Direction of an 0 angle is right
Vector2f getNewPos(Vector2f pos, int angle, float speed)
{
	Vector2f newPos;
	newPos.x = pos.x + speed*cos(angle*PI / 180);
	newPos.y = pos.y - speed*sin(angle*PI / 180); // screen Y grows downwards
	return newPos;
}

// Angle from one point to another, used for bullets aimed at the player
int getNewAngle(Vector2f pos1, Vector2f pos2)
{
	return -(90 - 180*atan2((pos2.x - pos1.x), (pos2.y - pos1.y))/PI);
}
```

### Bullet Patterns

Bullet-hell patterns are built from a few parameterised generators. The stage scripts combine them, changing speed, bullet count and arc, to create each attack.

```cpp
// bulletTrajectoryCalculation.hpp
// Ring of bullets fired from one point in every direction
void bulletsHell1(std::vector<Bullet> &bullet, Texture *BulletTex, Vector2f pos, float speed, int value)
{
	for (int i = 0; i < value; i++)
		bullet.push_back(Bullet(BulletTex, Bullet1, pos, i*(360/value), speed));
}

// Stage1.hpp, Rumia's opening attack: three rings with different density and speed
bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.1, 36);
bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.2, 24);
bulletsHell1(bullets, BulletTex, Vector2f(bosses[0].pos.x + 6, bosses[0].pos.y + 20), 0.3, 12);
```

### Stage Scripting: a phase counter

Stages use a timeline instead of a level editor. A global `stagePhase` counter advances on a fixed timer, and each phase spawns a wave of enemies, starts a boss attack or shows a line of dialogue.

```cpp
// Stage1.hpp: each phase spawns `enemyCounter` enemies, then moves to the next one
if (stagePhase == 0)
{
	if (enemyCounter)
	{
		// health, texture, 4 animation frames, spawn position, angle, speed,
		// timer, shooting strategy, shoot frequency, bullet speed
		enemies.push_back(Enemy(1, enemy1Texture, RectEnemy11, RectEnemy12, RectEnemy13, RectEnemy14,
		                        Vector2f(60, -15), 270, 0.1, time, 30, 99, 0.5));
		enemyCounter--;
	}
	else
	{
		stagePhase++;
		enemyCounter = 10; // size of the next wave
	}
}
// ...
// Pre2Hou.cpp: the script is advanced twice per second
if (stageClock.getElapsedTime().asSeconds() >= 0.5) { /* call Stage1(...) */ stageClock.restart(); }
```

### Collisions, Hitbox & Graze

The player has two collision shapes. A small, invisible **hitbox** decides whether a bullet hits, and the larger **sprite** detects grazes. Each bullet can be grazed only once.

```cpp
// Pre2Hou.cpp: enemy bullet loop
// Player and bullet collision: only the 10x10 hitbox counts
if (bullets[k].shape.getGlobalBounds().intersects(player.hitBox.getGlobalBounds()) && player.invulnerable == 0)
{
	player.setHp(player.getHP() - 1);
	player.power = player.power / 2;   // getting hit halves the power
	player.invulnerable = 1;           // ~3 s of invulnerability (sprite blinks)
	invClock.restart();
	// ...
}
// Graze: the bullet touched the sprite but not the hitbox
if (bullets[k].shape.getGlobalBounds().intersects(player.shape[Moved][player.CurrentFrame].getGlobalBounds()) && bullets[k].grazed)
{
	player.graze++;
	grazeSound.play();
	bullets[k].grazed = 0; // one graze per bullet
}
```

### Resource Loading

`FileManager` loads every SFML resource type through one template. Files that fail to load are collected into a list instead of crashing the game. `sf::Music` gets its own specialisation because it streams with `openFromFile`.

```cpp
// file_manager.cpp
template <typename T>
void FileManager::LoadFromFile(T &t, const std::string &file_name)
{
	if (!t.loadFromFile(file_name))
		missing_files.push_back(file_name);
}

// sf::Music streams from disk, so it uses openFromFile instead of loadFromFile
template<> void FileManager::LoadFromFile<sf::Music>(sf::Music &t, const std::string &file_name)
{
	if (!t.openFromFile(file_name))
		missing_files.push_back(file_name);
}
```

---

## 🔧 Building

1. Install [SFML 2.5.1](https://www.sfml-dev.org/) and set `SFMLDirectory` in `Pre2Hou/SFML.props` to its location.
2. Open `Pre2Hou.sln` in Visual Studio and build.
3. Run the game from the `Pre2Hou/` directory so that `img/`, `fonts/`, `sounds/` and `music/` can be found.

---

## 📝 Notes

- `AnimatedSprite.cpp` is a third-party helper by Maximilian Wagenbach (zlib license).
- All characters, graphics and music come from the Touhou Project and are © ZUN. This is a non-profit fan project.

<div align="center">

  **Pre2hou - a C++ / SFML bullet-hell learning project.**

</div>
