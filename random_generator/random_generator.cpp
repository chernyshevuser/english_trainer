#include "random_generator.h"

namespace random_generator {
    using std::set;

    std::set<size_t> GetRandomIndexes(int count, size_t maxSize) {
        set<size_t> randomIndexes;
        while (randomIndexes.size() < count) {
            randomIndexes.insert(rand() % (maxSize + 1));
        }
        return randomIndexes;
    }

}
