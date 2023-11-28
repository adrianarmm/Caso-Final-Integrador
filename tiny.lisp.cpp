#include <vector>
#include <string>
#include <map>
#include "json11.hpp"

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno;

class Json;

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

    Variant(variant_type type = variant_type::Symbol) : type(type), env(nullptr), proc(nullptr) {}
    Variant(variant_type type, const std::string& val) : type(type), val(val), env(nullptr), proc(nullptr) {}
    Variant(proc_type proc) : type(variant_type::Proc), proc(proc), env(nullptr) {}

    std::string to_string();
    std::string to_json_string();
    static Variant from_json_string(const std::string& json);
    static Variant parse_json(json11::Json job);
};
std::string Variant::to_string() {
}
std::string Variant::to_json_string() {
}
Variant Variant::from_json_string(const std::string& json) {
}