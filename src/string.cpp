#include <libcutils/libcutils.h>
#include <string>

extern "C" {

void std_string_string(void **sstr, const char *c_str) {
    if (*sstr != nullptr) {
        // construct with existing memory
        new (*sstr) std::string(c_str);
    } else {
        // construct with new memory
        *sstr = new std::string(c_str);
    }
}

const char *std_string_c_str(void *sstr) {
	return ((std::string*)sstr)->c_str();
}

void std_string_destroy(void *sstr, bool should_free) {
    if (should_free)
        delete (std::string*)sstr;
    else
        ((std::string*)sstr)->~basic_string();
}

}
