#include <vector>
#include <string>
#include <map>
#include "json11.hpp"

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno;

class Variant
        {
public:
    using proc_type = Variant(*)(const std::vector<Variant>&);
    using iter = std::vector<Variant>::const_iterator;
    using map = std::map<std::string, Variant>;

    variant_type type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;