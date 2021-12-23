//
// Created by Daniel Mints on 12/18/21.
//

#include "pdf.h"
#include <iostream>
#include <vector>

using namespace std;


int pdf::findFactorials(int a) {
    int product = 1;
    for (int i = 1; i <= a; i ++) {
        product *= i;
    }
    return product;
}

int pdf::combimationFinder (double n, double k) { return (findFactorials(n)) / (findFactorials(k) * findFactorials(n - k));}

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

    cout << "Such a PMF type does not exist there for exiting";
    return 0;
}