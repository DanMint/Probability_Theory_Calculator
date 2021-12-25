//
// Created by Daniel Mints on 12/18/21.
//

#ifndef PROBABILITY_THEORY_CALCULATOR_VARIANCE_H
#define PROBABILITY_THEORY_CALCULATOR_VARIANCE_H
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

class variance {
public:
    variance(int probabilitySpace ,int typeOfProbability, vector<double> needed) {
        // here find out to make it return to the console with an error message
        // what is std::move in vector
        this->probabilitySpace = probabilitySpace;
        this->typeOfProbability = typeOfProbability;
        this->needed = needed;

        /// 1 - is uniform distrib meaning it takes only one value to calculate the pdf (needed[0])
        /// 2 - is Bern distrib meaning the it also takes one value to calculate the expected value (needed[0])
        /// 3 - is Binomial distrib. 1st input is amount of playes. 2nd input is win percentage
        /// 4 - is Poiss distrib. 1st inout lambda
        /// 5 - is Geometric distrib, 1st  take in is the probability (p)
        vector<pair<int, double>> tempDiscrete = {{1, (pow(needed[0], 2) - 1) / 12}, {2, needed[0] * (1 - needed[0])}, {3, (needed[0] * needed[1]) * (1 - needed[1])}, {4, needed[0]}, {5, (1 - needed[0]) / pow(needed[0], 2)}};
        discreteProbabilities = tempDiscrete;

        /// 1 - is uniform segment. 1st input is the start of the segment (a). 2nd input is the end segment (b)
        /// 2 - is normal distribution. 1st input is the delta squared
        /// 3 - is expsonential distribution. 1st input will be the lambda
        /// 4 - is Cauchy. 1st input is the d.v (X). 2nd input is delta (𝜎)
        vector<pair<int, double>> tempContinuous = {{1, pow((needed[2] - needed[1]), 2) / 12}, {2, needed[0]}, {3, 1 / pow(needed[0], 2)}, {4, numeric_limits<double>::lowest()}};
        continuousProbabilities = tempContinuous;

        double neededExpectedVal = (probabilitySpace == 1) ? discreteVariance() : continuousVariance();

        if (neededExpectedVal == -1000000000000000)
            cout << "The expected value is: non existent because its Cauchy" << endl;

        else
            cout << "The expected value is: " << neededExpectedVal << endl;
    }

    double discreteVariance();

    double continuousVariance();

private:
    int probabilitySpace;
    int typeOfProbability;
    vector<double> needed;

    vector<pair<int, double>> discreteProbabilities;
    vector<pair<int, double>> continuousProbabilities;

};


#endif //PROBABILITY_THEORY_CALCULATOR_VARIANCE_H
