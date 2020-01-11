#pragma once
#include "BaseScene.hpp"



/*
ゲームクリアのシーンの大本
*/
class GameClear : public BaseScene
{
private:


public:
	GameClear();
	~GameClear();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};