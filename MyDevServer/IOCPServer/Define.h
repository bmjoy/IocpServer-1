#pragma once

#include "Protocol.h"

#define SOLO_NUM 2

struct stOverEx {
	WSAOVERLAPPED m_wsaOver;
	WSABUF m_wsaBuf;
	unsigned char m_IOCPbuf[MAX_BUFFER]; // IOCP send/recv ����
	unsigned char	m_todo;
	int id;
	int roomNum;
};
enum ThreadNum {
	ACCEPT_TH,
	WORKER_TH01,
	WORKER_TH02,
	WORKER_TH03,
	TIMER_TH
};
enum AVATARNumber {
	A, //�ӽø�Ī
	B
};
//enum MAPNumber {
//	PLAYGROUND,
//	CONCERT
//
//};
enum ModNumber {
	SOLO,
	DUO,
	SQUAD
};
enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
enum SceneState {
	MENUSCENE = 0,
	PLAYGROUNDMAP = 1,
	CONCERTMAP,
	GAMEOVER,
	LOADING
};
enum PlayerState {
	IDLE,
	RUN,
	JUMP,
	DEATH,
	STUN,
	HIT,
	JUMPROLL,
	RUN_JUMP_ATTAK,
	ATTACK,
	ATTACK_3,
	HAPPY,
	SAD,
	BACK_RUN,
};
enum Result {
	LOSE,
	WIN,
	ING
};