//
// Created by Daniel Mints on 12/18/21.
//

#include "pdf.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int pdf::findFactorials(int a) {
    int product = 1;
    for (int i = 1; i <= a; i ++) {
        product *= i;
    }
    return product;
}

int pdf::combinationFinder (double n, double k) { return (findFactorials(n)) / (findFactorials(k) * findFactorials(n - k));}

double pdf::pmfFinder() {
    for (const auto &el : discreteProbabilities) {
        if (el.first == typeOfProbability) {
            return el.second;
        }
    }
    cout << "Such a PMF type does not exist there for exiting";
    return 0;
}

double pdf::pdfFinder() {
    for (const auto &el : continuousProbabilities) {
        if (el.first == typeOfProbability) {
            return el.second;
        }
    }
    cout << "Such a PMF type does not exist there for exiting";
    return 0;
}

int pdf::containedInSegment(int randomVar, int startOfSegment, int endOfSegment) {
    if (randomVar < endOfSegment || randomVar > startOfSegment)
        return 1;
    return 0;
}

double pdf::normalPdf() {
    /// 2 - is normal distribution. 1st input is the d.v (X). 2nd input is the a. 3rd input is the delta squared
    double x = needed[0];
    double a = needed[1];
    double deltaSquared = needed[2];

    double firstPart = 1 / (pow((2 * 3.14 * deltaSquared), 0.5));
    double secondPart = exp(-(pow((x - a), 2)) / (2 * deltaSquared));

    return firstPart * secondPart;
}