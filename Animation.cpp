#include "Animation.h"

Animation::Animation(AnimationSprite* ani)
{
	animation = ani;
	delay = 0;
	start = 0;
	end = 0;
	Pause = false;

	scale = D3DXVECTOR2(1, 1);
	position = D3DXVECTOR2(0, 0);
	FlipFlag = false;
	angle = 0;
}

Animation::~Animation()
{
	delete animation;
}

int Animation::GetIndex()
{
	return Index;
}
void Animation::SetIndex(int index)
{
	Index = index;
}

void Animation::SetFrame(D3DXVECTOR2 Position, bool Flip, int Delay, int Start, int End)
{
	position = Position;
	FlipFlag = Flip;
	delay = Delay;
	start = Start;
	end = End;
	Index = Start;
}

void Animation::NewAnimationByIndex(int index)
{
	AnimationSprite::DataAnim data = animation->_dataAnim[index];
	start = data.start;
	end = data.end;
	delay = data.delay;
}

//Rect
RECT Animation::GetRectByIndex(int index)
{
	return animation->_infoAnim->GetRect(index);
}

InfoSprite::Infoframe Animation::GetCurrentFrameInfo()
{
	return animation->_infoAnim->GetInfoByIndex(Index);
}

bool Animation::GetFlipFlag()
{
	return FlipFlag;
}

int Animation::GetDelay()
{
	return delay;
}

int Animation::GetStart()
{
	return start;
}

int Animation::GetEnd()
{
	return end;
}

void Animation::SetPause(bool pause)
{
	Pause = pause;
}
void Animation::SetPause(bool pause, int index)
{
	IndexPause = index;
	Pause = pause;
}

D3DXVECTOR2 Animation::GetPosition()
{
	return position;
}
void Animation::SetPosition(D3DXVECTOR2 Position)
{
	position = Position;
}

void Animation::SetFlipFlag(bool flag)
{
	FlipFlag = flag;
}

//Lật hình theo trục y
void Animation::Flip(bool flag)
{
	if (flag)
	{
		scale = D3DXVECTOR2(-1, 1);
	}
	else scale = D3DXVECTOR2(1, 1);
}

void Animation::Update()
{
	//Chuyển frame tiếp theo
	if (TimeCurrent * 1000 >= delay)
	{
		TimeCurrent = 0;
		Index++;
	}
	else TimeCurrent += GameTime;
	//Lấy giá trị Index để vẽ Rect
	if (Index < start || Index > end)
	{
		Index = start;
	}
	//Kiểm tra Frame dừngz
	if (Pause)
	{
		Index = IndexPause;
	}
	//Set rect mới
	rect = GetRectByIndex(Index);
	//Lấy center
	center.x = (rect.right - rect.left) / 2;
	center.y = (rect.bottom - rect.top) / 2;
	////Kiểm tra center flip chỉnh transform
	transform.x = 0;
	transform.y = 0;
}

D3DXVECTOR2 Animation::GunPos(int index)
{
	auto config = animation->_infoAnim->GetInfoByIndex(animation->_dataAnim[index].start);
	if (config.sx != 0)
		return D3DXVECTOR2(config.sx, config.sy);
	return D3DXVECTOR2(0, 0);
}

void Animation::Render(Viewport* viewport)
{
	animation->SetData(rect, center, position, scale, transform, angle);
	animation->Flip(FlipFlag);
	animation->Render(viewport);
}

void Animation::Render()
{
	animation->SetData(rect, center, position, scale, transform, angle);
	animation->Flip(FlipFlag);
	animation->Render();
}