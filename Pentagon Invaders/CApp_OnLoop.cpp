#include "CApp.h"
#include "MovementHandler.h"
#include "Delta.h"
#include "LoopUtils.h"
#include "Vector2f.h"
 
void CApp::OnLoop() {
	Delta::set();

	SpaceShip& player = scene->getPlayerShip();

	// TODO keep player on screen
	MovementHandler::movePlayer(player);

	player.generateVertices();

	// TODO remove off-screen objects

	LoopUtils::moveBullets(*scene->getEnemyBullets());
	LoopUtils::moveBullets(*scene->getPlayerBullets());

	// TODO add bullets

	if (scene->getPlayerBullets()->empty())
	{
		scene->addPlayerBullet(new Bullet(Vector2f(512.0f, 200.0f),Vector2f(0.0f, 1.0f), 2.5f, 15.0f, 15));
	}

	// TODO create ships
}