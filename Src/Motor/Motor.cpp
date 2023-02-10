#include "Biblioteca/Biblioteca.h"
#include <OgreRoot.h>
#include <fstream>
#include <iostream>

int main()
{
	Ogre::Root* root;
	root = new Ogre::Root();
	saluda("XD");
	/* std::fstream f("Assets\\mapa.txt");
	if (f.is_open()) {
		std::cout << "FICHERO ABIERTO\n";
		f.close();
	}
	else {
		std::cerr << "FICHERO NO ABIERTO";
		return 1;
	}*/

	return 0;
}