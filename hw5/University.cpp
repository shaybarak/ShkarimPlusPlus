#include "University.h"

University& University::getInstance() {
    static University instance;
    return instance;
}
