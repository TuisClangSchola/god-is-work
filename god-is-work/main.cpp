#include <string>

#include "Manager.hpp"



/// -----------------------------------------------------------------------------------
// ウィンドウサイズを決める
int winWidth = 0;
int winHeight = 0;
int bitColor = 0;



/// -----------------------------------------------------------------------------------
bool Init(const int t_winWidth, const int t_winHeight, const int t_bitColor, std::string t_projectName)
{
	winWidth = t_winWidth;
	winHeight = t_winHeight;
	bitColor = t_bitColor;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ログテキスト出力する
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ログテキスト出力しない
#endif


	SetWindowText(t_projectName.c_str());					// メインウインドウのウインドウタイトルを変更する
	SetBackgroundColor(0, 0, 0);			// 背景色を白に変更
	ChangeWindowMode(TRUE);						// ウィンドウズモードにさせる


	SetGraphMode(winWidth, winHeight, bitColor);			// 画面サイズ設定
	GetDefaultState(&winWidth, &winHeight, &bitColor);		// デフォルトウィンドウ値を得る
	SetWindowSize(winWidth, winHeight);					// デフォルトウィンドウサイズに合わせてゲームサイズを変更

	SetAlwaysRunFlag(TRUE);				// 裏画面でも常にアクティブに変更

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return false;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);	// 背景描画
	
	return true;
}



/// -----------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (Init(1920, 1080, 32, "God-Is-Work") == false) return -1;

	InputControl::PadData::SetPadNum();

	Manager m_manager = Manager();

	// メインループ
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !InputControl::KeyData::IsCheckEnd() && !InputControl::PadData::IsCheckEnd() && !m_manager.GetEnd())
	{
		InputControl::KeyData::UpDate();
		InputControl::PadData::UpDate();


		m_manager.Update();


		DrawFormatString(0, 0, GetColor(255, 255, 255), "(0, 0)");
		DrawFormatString(1840, 0, GetColor(255, 255, 255), "(1920, 0)");
		DrawFormatString(0, 1060, GetColor(255, 255, 255), "(0, 1080)");
		DrawFormatString(1810, 1060, GetColor(255, 255, 255), "(1920, 1080)");
	}

	// 削除
	m_manager.~Manager();
	DxLib_End();		// DXライブラリの後始末


	return 0;
}