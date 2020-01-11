#pragma once
#include "BaseScene.hpp"



/*
ゲームオーバーのシーンの大本
*/
class GameOver : public BaseScene
{
private:


public:
	GameOver();
	~GameOver();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};