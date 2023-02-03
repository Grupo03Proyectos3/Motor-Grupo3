#include <iostream>
#include <fstream>
int main(){
    std::fstream f("Assets\\mapa.txt");
    if (f.is_open()) {
        std::cout << "FICHERO ABIERTO\n";
        f.close();
    }
    else {
        std::cerr << "FICHERO NO ABIERTO";
        return 1;
    }
    return 0;
}