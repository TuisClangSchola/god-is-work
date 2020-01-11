#include "Manager.hpp"



/// -----------------------------------------------------------------------------------
void Manager::SceneChange()
{
	if (p_baseMove != nullptr)
	{
		delete p_baseMove;
		p_baseMove = nullptr;
	}
	// 今のシーン
	switch (BASICPARAM::e_nowScene)
	{
		// ロゴ
	case ESceneNumber::TITLE_AND_MENU:
		p_baseMove = new TitleAndMenu();
		printfDx("TitleAndMenu\n");
		break;


		// タイトル
	case ESceneNumber::GAME:
		p_baseMove = new Game();
		printfDx("Game\n");
		break;


		// チュートリアル
	case ESceneNumber::GAMECLEAR:
		p_baseMove = new GameClear();
		printfDx("GameClear\n");
		break;


		// ゲーム本編
	case ESceneNumber::GAMEOVER:
		p_baseMove = new GameOver();
		printfDx("GameOver\n");
		break;


	default:
		break;
	}
}



/// -----------------------------------------------------------------------------------
Manager::Manager()
{
	p_baseMove = nullptr;

	BASICPARAM::e_nowScene = ESceneNumber::TITLE_AND_MENU;
	BASICPARAM::e_preScene = ESceneNumber::TITLE_AND_MENU;

	p_baseMove = new TitleAndMenu();
}



/// -----------------------------------------------------------------------------------
Manager::~Manager()
{
	if (p_baseMove != nullptr) delete p_baseMove;
}



/// -----------------------------------------------------------------------------------
void Manager::Update()
{
	// 現在のシーンと直前のシーンが同じとき
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)
	{
		// ゲームの描画に関する
		p_baseMove->Draw();


		// ゲームのプロセスに関する
		p_baseMove->Process();
	}
	// 現在と直前のシーンが異なったら
	else
	{
		// シーンを変える
		SceneChange();


		// 直前のシーンと現在のシーンを同じにする
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}