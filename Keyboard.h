﻿#pragma once
#include <dinput.h>

class Keyboard
{
	static Keyboard* _keyboard;

	//Đối tượng nhập xuất
	LPDIRECTINPUT8 Di8;
	//Thiết bị nhập xuất
	LPDIRECTINPUTDEVICE8 DiD8;
	//Buffer lưu dữ liệu lấy từ thiết bị
	char key_buffer[256];
	////Hiển thị của chương trình
	//HINSTANCE Hinstance;
	//Handle cửa sổ vẽ
	HWND Hwnd;

public:
	//Contructor
	Keyboard();
	~Keyboard();
	//Cài đặt bàn phím
	bool Init(HWND hwnd);
	//Lấy trạng thái bàn phím
	void GetStage();
	//Nhận diện phím nhấn
	bool IsKeyDown(int key);
	//Kiểm tra trạng thái phím có đang down
	bool GIsKeyDown(int key);
	//Kiểm tra trạng thái phím có đang up
	bool GIsKeyUp(int key);
	//Hủy phím
	void KillKeyboard();

	static Keyboard* GetInstance();
};

