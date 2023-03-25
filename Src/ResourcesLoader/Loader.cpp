#include "Loader.h"

void Loader::findDir(const char* t_path, std::ofstream& t_output)
{
    DIR* dir = opendir(t_path); //Abrir el directorio
    if (dir == nullptr) //Aserguarse que el directorio existe
    {
        std::cerr << "Error al abrir el directorio " << t_path << std::endl;
        return;
    }

    dirent* entry = readdir(dir); //Me guardo el archivo
    while (entry != nullptr) //Mientras haya encontrado algo
    {
        if (entry->d_type == DT_DIR) //Si el archivo es un directorio
        {
            // Si es un subdirectorio, ignorar "." y ".."
            if (std::strcmp(entry->d_name, ".") == 0 || std::strcmp(entry->d_name, "..") == 0)
            {
                entry = readdir(dir);
                continue;
            }
            std::cout << "Subdirectorio encontrado: " << entry->d_name << std::endl;
            char subpath[PATH_MAX]; //Me guardare la ruta completa de ese directorio
            std::snprintf(subpath, PATH_MAX, "%s/%s", t_path, entry->d_name);
            //Escribe esa ruta el el resources.cfg
            t_output << "FileSystem=" << subpath << '\n';
            //Llamada recursiva para abrir ese diretorio
            findDir(subpath, t_output);
        }
        else //Si el archivo no es directorio
        {
            //Me guardo en "subpath" la ruta de ese archivo
            char subpath[PATH_MAX];
            std::snprintf(subpath, PATH_MAX, "%s/%s", t_path, entry->d_name);
            //Convierto la ruta a string
            std::string x = subpath;
            std::string aux = x.substr(x.size() - 3, 1) + x.substr(x.size() - 2, 1) + x.substr(x.size() - 1, 1);
            //Si ese archivo es un .zip
            if (aux == "zip")
            {
                t_output << "Zip=" << x << '\n';
            }
        }
        entry = readdir(dir); //Actualizo la entrada
    }

    closedir(dir); //Cerrar el directorio abierto anteriormente
}

void Loader::loadDirectories()
{
    const char* directory = "./Assets";    // Directorio donde estan todos los recursos que buscar
    std::ifstream infile("resources.cfg"); // Archivo de input
    std::string line;                      // Linea donde se guarda cada linea leida
    std::vector<std::string> text;         // Vector donde me guardo todo el texto leido. Cada componente del vector es una linea

    // si no puede abrir resources.cfg ERROR
    try
    {
        if (!infile)
        {
            throw std::ifstream::failure("resources.cfg dont found");
        }
    }
    catch (std::ifstream::failure& excepcion)
    {
        std::cerr << "Error: " << excepcion.what() << '\n';
        exit(1);
    }

    while (line != "FileSystem=./Assets") // Leo hasta "FileSystem=./Assets" que es lo que no quiero sobreescribir
    {
        getline(infile, line);
        text.push_back(line);
    }
    infile.close(); // Cierro el archivo

    std::ofstream output("resources.cfg" /*, std::ios::app | std::ios::ate*/); // Archivo para output
    for (int i = 0; i < text.size(); i++)                                      // Escribo en el archivo todas las lineas anteriores que quiero conservar
    {
        line = text[i];
        output << line << '\n';
    }
    // Metod0 recursivo para buscar todos los directorios
    findDir(directory, output);
    // Cierro el archivo ���IMPORTANTE PARA QUE SE HAGA BIEN LA LECTURA Y ESCRITURA!!!
    output.close();
}