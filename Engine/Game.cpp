/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (isLeftRelease&&wnd.kbd.KeyIsPressed(VK_LEFT))
		v_x -= 1;
	if (!wnd.kbd.KeyIsPressed(VK_LEFT))
		isLeftRelease = true;
	else
		isLeftRelease = false;
	if (isRightRelease&&wnd.kbd.KeyIsPressed(VK_RIGHT))
		v_x += 1;
	if (!wnd.kbd.KeyIsPressed(VK_RIGHT))
		isRightRelease = true;
	else
		isRightRelease = false;
	if (isUpRelease&&wnd.kbd.KeyIsPressed(VK_UP))
		v_y -= 1;
	if (!wnd.kbd.KeyIsPressed(VK_UP))
		isUpRelease = true;
	else
		isUpRelease = false;
	if (isDownRelease&&wnd.kbd.KeyIsPressed(VK_DOWN))
		v_y += 1;
	if (!wnd.kbd.KeyIsPressed(VK_DOWN))
		isDownRelease = true;
	else
		isDownRelease = false;

	x_move += v_x;
	y_move += v_y;

	OutScreenTest(x_move, y_move);

	isCollide = OverLapTest(x_move, y_move, x_fixed, y_fixed);

	
}

void Game::ComposeFrame()
{
	DrawBox(x_fixed, y_fixed, colorR_fixed, colorG_fixed, colorB_fixed);
	if (isCollide)
		DrawBox(x_move, y_move, colorChangeR_move, colorChangeG_move, colorChangeB_move);
	else
		DrawBox(x_move, y_move, colorR_move, colorG_move, colorB_move);

}

void Game::DrawCross(int x, int y, int r, int g, int b)
{
	for (int i = -5; i<6; i++)
		if (i < -2 || i>2)
		{
			gfx.PutPixel(x + i, y, r, g, b);
			gfx.PutPixel(x, y + i, r, g, b);
		}
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	for (int i = -5; i<6; i++)
		if (i < -2 || i>2)
		{
			gfx.PutPixel(x + i, y + 5, r, g, b);
			gfx.PutPixel(x + i, y - 5, r, g, b);
			gfx.PutPixel(x - 5, y + i, r, g, b);
			gfx.PutPixel(x + 5, y + i, r, g, b);
		}
}

bool Game::OverLapTest(int box0x, int box0y, int box1x, int box1y)
{
	int xMin_fixed = box0x - 5;
	int xMax_fixed = box0x + 5;
	int yMin_fixed = box0y - 5;
	int yMax_fixed = box0y + 5;
	int xMin_move = box1x - 5;
	int xMax_move = box1x + 5;
	int yMin_move = box1y - 5;
	int yMax_move = box1y + 5;


	return (xMin_fixed<=xMax_move&&
		xMax_fixed>=xMin_move&&
		yMin_fixed<=yMax_move&&
		yMax_fixed>=yMin_move);
}

void Game::OutScreenTest(int & x, int & y)
{

	if ((x + 5) >= gfx.ScreenWidth)
		x = gfx.ScreenWidth - 6;
	if ((x - 5) <= 0)
		x = 6;
	if ((y + 5) >= gfx.ScreenHeight)
		y = gfx.ScreenHeight - 6;
	if ((y - 5) <= 0)
		y = 6;
}
