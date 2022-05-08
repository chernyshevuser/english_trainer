#pragma once

#include <deque>
#include <iostream>
#include <map>
#include <string_view>
#include <vector>
#include <utility>
#include <set>
#include <optional>

namespace translator {

    using std::string_view;
    using std::string;
    using std::map;
    using std::deque;
    using std::vector;
    using std::pair;
    using std::set;
    using std::optional;


    enum class Language {
        RUSSIAN,
        ENGLISH,
    };

    class Translator {
    public:
        Translator() = default;

        //source - английское слово, target - русское слово
        void Add(string_view source, string_view target);

        //перевод с английского на русский
        string_view TranslateForward(string_view source) const;

        //перевод с русского на английский
        string_view TranslateBackward(string_view target) const;


        template <class C>
        vector<pair<string_view, string_view>> GetTrainingWords(set<size_t> randomIndexes,
                                                                C& container);


        // если language == ENGLISH, то тестируется перевод с английского на русский
        // если language == RUSSIAN, то тестируется перевод с русского на английский
        optional<vector<pair<string_view, string_view>>> ComputeTrainingWords(int count, Language language);

    private:
        //перевод с английского на русский
        map<string, string> forwardTranslate_;
        //перевод с русского на английский
        map<string_view, string_view> backwardTranslate_;
    };

}