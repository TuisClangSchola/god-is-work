#pragma once
#include "BaseScene.hpp"
#include "TitleAndMenu.hpp"
#include "Game.hpp"
#include "GameClear.hpp"
#include "GameOver.hpp"



/*
ゲームの大本
*/
class Manager
{
private:
	BaseScene* p_baseMove;	// シーンの基底クラス

	// シーンを切り替える
	void SceneChange();


public:
	Manager();
	~Manager();


	// メインプロセス
	void Update();

	// 終了させる
	const bool GetEnd() const { return p_baseMove->GetEnd(); }
};