#include "GameOver.hpp"



/// -----------------------------------------------------------------------------------
GameOver::GameOver()
{
}



/// -----------------------------------------------------------------------------------
GameOver::~GameOver()
{
}



/// -----------------------------------------------------------------------------------
void GameOver::Draw()
{
}



/// -----------------------------------------------------------------------------------
void GameOver::Process()
{
	if (InputControl::KeyData::Get(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::e_nowScene = ESceneNumber::TITLE_AND_MENU;
	}
}
