#ifdef FLAMINGOEXPORT_EXPORTS
#define FLAMINGOEXPORT_API __declspec(dllexport)
#else
#define FLAMINGOEXPORT_API __declspec(dllimport)
#endif