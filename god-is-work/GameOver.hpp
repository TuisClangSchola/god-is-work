#pragma once
#include "BaseScene.hpp"



/*
�Q�[���I�[�o�[�̃V�[���̑�{
*/
class GameOver : public BaseScene
{
private:


public:
	GameOver();
	~GameOver();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};