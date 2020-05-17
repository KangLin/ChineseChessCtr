
#ifndef _CHESS_GAME_KL_2020_05_15_
#define _CHESS_GAME_KL_2020_05_15_

#pragma once

#include "Piece.h"
#include <vector>

/**
 * 棋局
 * 完成棋局的加载、保存、复盘
 *
 * @author KangLin(kl222@126.com)
 * @date 2020/5/17
 */
class CChessGame
{
public:
	CChessGame();
	virtual ~CChessGame();

	// 调整棋局存储大小
	int SaveStep(int i, int j, CPiece::ENUM_QiZi qz); //保存当前步
	int RevokeStep();								  //撤回当前步

	// 移动指针位置
    int GetPreviouStep(int &i, int &j, CPiece::ENUM_QiZi &qz); //得到上一步
	int GetNextStep(int &i, int &j, CPiece::ENUM_QiZi &qz);	   //得到下一步

//int ReStart();                               //重新开始
	//int SaveChess(char* pFileName);          //保存棋局
//int LoadChess(char* pFileName);          //装载棋局，并设置为结束状态
//int LoadChessStart(char* pFileName);     //装载棋局，并设置为开始状态

private:
	struct strCODE{
		char code[3];
	};
	typedef enum _ENUM_BianMa {
		BianMa, 
		JieMa
	} ENUM_BianMa;
	int QiZiBianMa(int *i, int *j, CPiece::ENUM_QiZi *qz, strCODE *pCode, ENUM_BianMa bianma = BianMa);

	int m_nIndex;				  //走棋步数
	bool m_bFuPang;				  //复盘标志
	std::vector<strCODE> m_ChessGame; //棋局

};

#endif //_CHESS_GAME_KL_2020_05_15_