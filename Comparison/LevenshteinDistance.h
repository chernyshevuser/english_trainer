#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <string_view>

namespace levenshtein_distance {

    static int INF = 1e3;

    // стоимость удаления символа из первой строки - случай не имеет смысла
    static int DELETE_FIRST_COST = INF;

    // стоимость удаления символа из второй строки
    static int DELETE_SECOND_COST = 1;

    // стоимость замены символа первой строки на символ второй строки - случай не имеет смысла
    static int CHANGE_FIRST_TO_SECOND = INF;

    // стоимость замены символа второй строки на символ первой строки
    static int CHANGE_SECOND_TO_FIRST = 1;


    int ComputeLevenshteinDistance(const std::string_view &first, const std::string_view &second);
}

