#include "game.h"

void Game::run() {
	Timer timer;

	entityManager.addPlayer(
		(float)window.windowWidth  / 2,
		(float)window.windowHeight / 2
	);

	window.renderWindow([&]() {
		entityManager.updateEntities();
		entityManager.getPlayer()->input->replicateInput(window.input);
		entityManager.enemySpawner(
			timer.getElapsedTime(),
			(float)window.windowWidth,
			(float)window.windowHeight
		);
		movement.processEntitiesMovement(entityManager.getEntities());
		window.renderEntities(entityManager.getEntities());
	});
}