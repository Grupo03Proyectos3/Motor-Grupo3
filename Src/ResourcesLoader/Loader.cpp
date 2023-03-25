#include "Loader.h"


// Convierte la ruta obtenida al formato de resources.cfg
std::string Loader::parsePath(std::string t_path)
{
    std::string new_Path = t_path;          // Creo otro string del mimo tama�o que "path"
    for (int i = 0; i < t_path.size(); i++) // En "newPath" me guardo la ruta pero con el formato adecuado
    {
        if (t_path[i] == '\\')
        {
            new_Path[i] = '/';
        }
        else
            new_Path[i] = t_path[i];
    }
    return new_Path;
}

void Loader::findDir(const char* path, std::ofstream& t_output)
{
    DIR* dir = opendir(path);
    if (dir == nullptr)
    {
        std::cerr << "Error al abrir el directorio " << path << std::endl;
        return;
    }

    dirent* entry = readdir(dir);
    while (entry != nullptr)
    {
        if (entry->d_type == DT_DIR)
        {
            // Si es un subdirectorio, ignorar "." y ".."
            if (std::strcmp(entry->d_name, ".") == 0 || std::strcmp(entry->d_name, "..") == 0)
            {
                entry = readdir(dir);
                continue;
            }
            // Si es un directorio, llamar a esta misma función recursivamente
            std::cout << "Subdirectorio encontrado: " << entry->d_name << std::endl;
            char subpath[PATH_MAX];
            std::snprintf(subpath, PATH_MAX, "%s/%s", path, entry->d_name);
            t_output << "FileSystem=" << subpath << '\n';
            findDir(subpath, t_output);
        }
        else
        {
            //// Si es un archivo, mostrar su nombre
            //std::cout << "Archivo encontrado: " << entry->d_name << std::endl;
            char subpath[PATH_MAX];
            std::snprintf(subpath, PATH_MAX, "%s/%s", path, entry->d_name);
            std::string x = subpath;
            std::string aux = x.substr(x.size() - 3, 1) + x.substr(x.size() - 2, 1) + x.substr(x.size() - 1, 1);
            if (aux == "zip")
            {
                x = parsePath(x);
                t_output << "Zip=" << x << '\n';
            }
        }
        entry = readdir(dir);
    }

    closedir(dir);
    //for (const auto& entry : t_dir) // Burco los directorios dentro de "directory"
    //{
    //    if (entry.is_directory()) // Si es un fichero tipo directorio
    //    {
    //        std::string path = entry.path().string(); // Me guardo su ruta en "path"
    //        std::string new_Path = parsePath(path);
    //        // Escribe en el archivo todas las rutas que encuentro
    //        t_output << "FileSystem=" << new_Path << '\n';
    //        std::filesystem::directory_iterator d(new_Path);
    //        findDir(d, t_output);
    //    }
    //    else
    //    {
    //        std::string x = entry.path().string();
    //        std::string aux = x.substr(x.size() - 3, 1) + x.substr(x.size() - 2, 1) + x.substr(x.size() - 1, 1);
    //        if (aux == "zip")
    //        {
    //            x = parsePath(x);
    //            t_output << "Zip=" << x << '\n';
    //        }
    //    }
    //}
}

void Loader::loadDirectories()
{
    //std::string directory = "./Assets";    // Directorio donde estan todos los recursos que buscar
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

    //std::filesystem::directory_iterator dir;

    //// abrimos el directorio y si lanza excepcion la capturamos
    //try
    //{
    //    dir = std::filesystem::directory_iterator(directory); // si no existe la carpeta de Assets lanzamos excepcion
    //}
    //catch (std::filesystem::filesystem_error& e)
    //{
    //    std::cerr << "ERROR: " << e.what() << "\n";
    //    exit(1);
    //}
    //// Metod recursivo para buscar todos los directorios
    findDir(directory, output);

    output.close(); // Cierro el archivo ���IMPORTANTE PARA QUE SE HAGA BIEN LA LECTURA Y ESCRITURA!!!
}