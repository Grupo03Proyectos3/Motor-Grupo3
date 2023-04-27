// El siguiente bloque ifdef muestra la forma estándar de crear macros que hacen la exportación
// de un DLL más sencillo. Todos los archivos de este archivo DLL se compilan con FLAMINGOEXPORT_EXPORTS
// símbolo definido en la línea de comandos. Este símbolo no debe definirse en ningún proyecto
// que use este archivo DLL. De este modo, otros proyectos cuyos archivos de código fuente incluyan el archivo verán
// interpretan que las funciones FLAMINGOEXPORT_API se importan de un archivo DLL, mientras que este archivo DLL interpreta los símbolos
// definidos en esta macro como si fueran exportados.
#ifdef FLAMINGOEXPORT_EXPORTS
#define FLAMINGOEXPORT_API __declspec(dllexport)
#else
#define FLAMINGOEXPORT_API __declspec(dllimport)
#endif

// Clase exportada del DLL
class FLAMINGOEXPORT_API CFlamingoExport
{
    static CFlamingoExport* _instance;

  public:
    static bool Init();
    static CFlamingoExport* Instance();
    void DoSomething();
    CFlamingoExport(void);
};
extern FLAMINGOEXPORT_API int nFlamingoExport;

FLAMINGOEXPORT_API int fnFlamingoExport(void);
