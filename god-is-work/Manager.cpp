#include "Manager.hpp"



/// -----------------------------------------------------------------------------------
void Manager::SceneChange()
{
	if (p_baseMove != nullptr)
	{
		delete p_baseMove;
		p_baseMove = nullptr;
	}
	// ���̃V�[��
	switch (BASICPARAM::e_nowScene)
	{
		// ���S
	case ESceneNumber::TITLE_AND_MENU:
		p_baseMove = new TitleAndMenu();
		printfDx("TitleAndMenu\n");
		break;


		// �^�C�g��
	case ESceneNumber::GAME:
		p_baseMove = new Game();
		printfDx("Game\n");
		break;


		// �`���[�g���A��
	case ESceneNumber::GAMECLEAR:
		p_baseMove = new GameClear();
		printfDx("GameClear\n");
		break;


		// �Q�[���{��
	case ESceneNumber::GAMEOVER:
		p_baseMove = new GameOver();
		printfDx("GameOver\n");
		break;


	default:
		break;
	}
}



/// -----------------------------------------------------------------------------------
Manager::Manager()
{
	p_baseMove = nullptr;

	BASICPARAM::e_nowScene = ESceneNumber::TITLE_AND_MENU;
	BASICPARAM::e_preScene = ESceneNumber::TITLE_AND_MENU;

	p_baseMove = new TitleAndMenu();
}



/// -----------------------------------------------------------------------------------
Manager::~Manager()
{
	if (p_baseMove != nullptr) delete p_baseMove;
}



/// -----------------------------------------------------------------------------------
void Manager::Update()
{
	// ���݂̃V�[���ƒ��O�̃V�[���������Ƃ�
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)
	{
		// �Q�[���̕`��Ɋւ���
		p_baseMove->Draw();


		// �Q�[���̃v���Z�X�Ɋւ���
		p_baseMove->Process();
	}
	// ���݂ƒ��O�̃V�[�����قȂ�����
	else
	{
		// �V�[����ς���
		SceneChange();


		// ���O�̃V�[���ƌ��݂̃V�[���𓯂��ɂ���
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}