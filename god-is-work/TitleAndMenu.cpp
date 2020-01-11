#include "TitleAndMenu.hpp"



/// -----------------------------------------------------------------------------------
TitleAndMenu::TitleAndMenu()
{
}



/// -----------------------------------------------------------------------------------
TitleAndMenu::~TitleAndMenu()
{
}



/// -----------------------------------------------------------------------------------
void TitleAndMenu::Draw()
{
}



/// -----------------------------------------------------------------------------------
void TitleAndMenu::Process()
{
	if (InputControl::KeyData::Get(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::e_nowScene = ESceneNumber::GAME;
	}
}
