#include "Map.h"
#include"FrkShareControl.h"
void Map::loadMaxtrix(string path)
{
	fstream open(path);
	open >> this->_row;
	open >> this->_column;
	this->_matrix = new int*[this->_row];
	for (int j = 0; j<this->_row; j++)
	{
		this->_matrix[j] = new int[this->_column];
	}
	for (int i = 0; i<this->_row; i++)
	{
		for (int j = 0; j<_column; j++)
		{
			open >> this->_matrix[i][j];
		}
	}
	open.close();
}
void Map::Init(string path, FrkTexture* texture)
{
	this->loadMaxtrix(path);
	this->_texture = texture;
}
void Map::Update()
{

}
void Map::Render()
{
	for (int i = this->_row - 1; i >= 0; i--)
	{
		for (int j = 0; j < this->_column; j++)
		{
			RECT s_rect;
			s_rect.left = (this->_matrix[i][j]) * 16;
			s_rect.right = s_rect.left + 16;
			s_rect.top = 0;
			s_rect.bottom = 16;

			RECT des_rect;
			des_rect.left = j * 16;
			des_rect.right = (j + 1) * 16;

			des_rect.top =i * 16;
			des_rect.bottom = des_rect.top + 16;			
			_LocalGraphic->tDrawTexture(this->_texture, s_rect, des_rect, D3DXVECTOR2(8, 8), D3DCOLOR_XRGB(255, 255, 255), 0.1);
		}
	}
}
Map::Map()
{
		
}


Map::~Map()
{
}
