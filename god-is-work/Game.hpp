#pragma once
#include "BaseScene.hpp"



/*
�Q�[���̃V�[���̑�{
*/
class Game : public BaseScene
{
private:


public:
	Game();
	~Game();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};