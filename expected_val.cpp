//
// Created by Daniel Mints on 12/18/21.
//

#include "expected_val.h"

double expected_val::discreteExpectedValue() {
    for (const auto &el : discreteProbabilities) {
        if (el.first == typeOfProbability) {
            return el.second;
        }
    }
    return 0.;
}

double expected_val::continuousExpectedValue() {
    if (typeOfProbability == 4) {
        return -1000000000000000;
    }

    for (const auto &el : continuousProbabilities) {
        if (el.first == typeOfProbability) {
            return el.second;
        }
    }
    return 0.;
}