#ifndef __ACTOR_UNIT_H__
#define __ACTOR_UNIT_H__
/*******************************************
角色模块基础类
******************************************/
class CDoer;
class CPlayer;

class CDoerUnit
{
public:
	CDoerUnit();
	virtual ~CDoerUnit();

	//初始化模块
	virtual bool init();
	//读取模块数据
	virtual bool loadData(CDataPacketReader &data);
	//保存模块数据
	virtual void saveData(CDataPacket& data);
	//分派网络消息
	virtual void dispatchRecvPacket(int btCmd, CDataPacketReader &inPacket);
	//分派角色模块消息
	virtual void dispatchMsg(DoerMsg *msg);
	//玩家离线
	virtual void offline();

public:
	CDoer	*	m_pActor;//所属角色对象
	CPlayer	*	m_pPlayer;//所属玩家对象，如果模块不归属于玩家，则为空
};

#endif