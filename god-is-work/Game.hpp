#pragma once
#include "BaseScene.hpp"



/*
ゲームのシーンの大本
*/
class Game : public BaseScene
{
private:


public:
	Game();
	~Game();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};