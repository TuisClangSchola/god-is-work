#pragma once
#include "BaseScene.hpp"



/*
タイトルとメニューのシーンの大本
*/
class TitleAndMenu : public BaseScene
{
private:


public:
	TitleAndMenu();
	~TitleAndMenu();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};