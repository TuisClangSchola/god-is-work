#pragma once
#include "BaseScene.hpp"



/*
�Q�[���N���A�̃V�[���̑�{
*/
class GameClear : public BaseScene
{
private:


public:
	GameClear();
	~GameClear();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};