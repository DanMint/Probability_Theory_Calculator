//
// Created by Daniel Mints on 12/18/21.
//

#include "variance.h"

double variance::discreteVariance() {
    for (const auto &el : discreteProbabilities) {
        if (el.first == typeOfProbability) {
            return el.second;
        }
    }
    return 0.;
}

double variance::continuousVariance() {
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
