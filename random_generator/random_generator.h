#pragma once

#include <stdlib.h>
#include <set>

namespace random_generator {

    std::set<size_t> GetRandomIndexes(int count, size_t maxSize);

}
