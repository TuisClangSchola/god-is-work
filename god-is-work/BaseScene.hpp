#pragma once
#include "DxLib.h"
#include "InputController.hpp"


// �V�[���̓���
enum class ESceneNumber
{
	TITLE_AND_MENU,

	GAME,

	GAMEOVER,
	GAMECLEAR
};


// �S�̂ŕK�v�ȕϐ�
namespace BASICPARAM
{
	// ���O�̃V�[��
	extern ESceneNumber e_preScene;

	// ���݂̃V�[��
	extern ESceneNumber e_nowScene;
}


/*
���[�u�̑�{
*/
class BaseScene
{
protected:
	// �����I���t���b�O
	bool m_endFlag = false;


public:
	virtual ~BaseScene() {};

	// �`��
	virtual void Draw() = 0;

	// �v���Z�X
	virtual void Process() = 0;


	// �����I�ɏI��������
	const bool GetEnd() const { return m_endFlag; }
};