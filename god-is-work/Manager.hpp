#pragma once
#include "BaseScene.hpp"
#include "TitleAndMenu.hpp"
#include "Game.hpp"
#include "GameClear.hpp"
#include "GameOver.hpp"



/*
�Q�[���̑�{
*/
class Manager
{
private:
	BaseScene* p_baseMove;	// �V�[���̊��N���X

	// �V�[����؂�ւ���
	void SceneChange();


public:
	Manager();
	~Manager();


	// ���C���v���Z�X
	void Update();

	// �I��������
	const bool GetEnd() const { return p_baseMove->GetEnd(); }
};