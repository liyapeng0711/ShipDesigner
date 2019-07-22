/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawCross(int x, int y, int r, int g, int b);
	void DrawBox(int x, int y, int r, int g, int b);
	bool OverLapTest(int box0x, int box0y, int box1x, int box1y);
	void OutScreenTest(int& x, int& y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int x_fixed = 300;
	int y_fixed = 300;
	int colorR_fixed = 0;
	int colorG_fixed = 255;
	int colorB_fixed = 0;
	
	int x_move = 400;
	int y_move = 400;
	int colorR_move = 255;
	int colorG_move = 255;
	int colorB_move = 255;
	int colorChangeR_move = 255;
	int colorChangeG_move = 0;
	int colorChangeB_move = 0;

	bool isLeftRelease = false;
	bool isRightRelease = false;
	bool isUpRelease = false;
	bool isDownRelease = false;

	int v_x = 0;
	int v_y = 0;

	bool isCollide = true;
	/********************************/
};