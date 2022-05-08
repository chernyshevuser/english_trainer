#include "Translator.h"
#include "../random_generator/random_generator.h"

namespace translator {

    void Translator::Add(string_view source, string_view target) {
        auto itForward = forwardTranslate_.find(string(source));

        if (itForward != forwardTranslate_.end()) {
            auto itBackward = backwardTranslate_.find(itForward->second);
            backwardTranslate_.erase(itBackward);
        }

        //можно обойтись без find, нужно додумать
        forwardTranslate_[string(source)] = string(target);
        itForward = forwardTranslate_.find(string(source));
        backwardTranslate_[itForward->second] = itForward->first;
    }


    string_view Translator::TranslateForward(string_view source) const {
        auto it = forwardTranslate_.find(string(source));
        if (it == forwardTranslate_.end()) {
            return "ERROR: WORD DOES NOT EXIST";
        }
        return string_view(it->second);
    }


    string_view Translator::TranslateBackward(string_view target) const {
        auto it = backwardTranslate_.find(target);
        if (it == backwardTranslate_.end()) {
            return "ERROR: WORD DOES NOT EXIST";
        }
        return it->second;
    }


    template <class C>
    vector<pair<string_view, string_view>> Translator::GetTrainingWords(set<size_t> randomIndexes,
                                                            C& container) {
        vector<pair<string_view, string_view>> trainingWords;

        auto indIt = randomIndexes.begin();
        auto containerIt = container.begin();
        size_t curInd = 0;

        while (indIt != randomIndexes.end()) {
            if (curInd == *indIt) {
                trainingWords.push_back(*containerIt);
                indIt = next(indIt);
            }

            containerIt = next(containerIt);
        }

        return trainingWords;
    }

    optional<vector<pair<string_view, string_view>>> Translator::ComputeTrainingWords(
            int count, Language language) {

        if (count == 0 or forwardTranslate_.empty()) {
            return {};
        }

        set<size_t> randomIndexes = random_generator::GetRandomIndexes(count, forwardTranslate_.size());

        if (language == Language::ENGLISH) {
            return GetTrainingWords(randomIndexes, forwardTranslate_);
        }
        else if (language == Language::RUSSIAN) {
            return GetTrainingWords(randomIndexes, backwardTranslate_);
        }

        return {};
    }

}