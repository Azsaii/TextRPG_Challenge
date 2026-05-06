#include "GameManager.h"

int main(void) {

	GameManager* gameManager = GameManager::GetInstance();
	gameManager->StartPlayerSetting();
	gameManager->MainMenuProc();

	return 0;
}