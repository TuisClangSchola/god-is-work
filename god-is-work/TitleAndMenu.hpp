#pragma once
#include "BaseScene.hpp"



/*
�^�C�g���ƃ��j���[�̃V�[���̑�{
*/
class TitleAndMenu : public BaseScene
{
private:


public:
	TitleAndMenu();
	~TitleAndMenu();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};