#include "user_prefs.h"



UserPrefs::UserPrefs() {
	canvasSleshTilemap = false;
	textureTank.resize(0);
	textureTank.reserve(15);
}

void UserPrefs::change_texture(int index) {
	
	current_texture = &textureTank[index - 1];

}