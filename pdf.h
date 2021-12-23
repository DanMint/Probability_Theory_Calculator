//
// Created by Daniel Mints on 12/18/21.
//

#ifndef PROBABILITY_THEORY_CALCULATOR_PDF_H
#define PROBABILITY_THEORY_CALCULATOR_PDF_H
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>

using namespace std;
class pdf {
public:
    /// vector disc and cont are basically the type of probability and needed is the the parameters that also need to be
    /// passed to calculate the pdf
    pdf(int probabilitySpace ,int typeOfProbability, vector<double> needed) {
        // here find out to make it return to the console with an error message
        // what is std::move in vector
        this->probabilitySpace = probabilitySpace;
        this->typeOfProbability = typeOfProbability;
        this->needed = needed;

        /// 1 - is uniform distrib meaning it takes only one value to calculate the pdf (needed[0])
        /// 2 - is Bern distrib meaning the it also takes one value to v the pdf (needed[0])
        /// 3 - is Binomial distrib. 1st take in - amount of wins d.v (x). 2nd take in is number of games (n). third take in is prob to win (P)
        /// 4 - is Poiss distrib. 1st take in will be the discrete var (X). 2nd take in is the lambda
        /// 5 - is Geometric distrib, 1st take in is the d.v (x). 2nd take in is the probability (p)
        vector<pair<int, double>> tempDiscrete = {{1, 1 / needed[0]}, {2, needed[0]}, {3, combimationFinder(needed[1], needed[0]) * pow(needed[2], needed[0]) * pow((1. - needed[2]), (needed[1] - needed[0]))}, {4, (pow(needed[1], needed[0]) /
                findFactorials(needed[0])) * pow(2.14, -needed[1])}, {5, pow(1 - needed[1], needed[0] - 1) * needed[1]}};
        discreteProbabilities = tempDiscrete;

        /// 1 - is uniform segment. 1st inout
        /// 2 - is normal distribution. 1st input is the d.v (X). 2nd input is the a and the last input is the delta squared
        /// 3 - is expsonential distribution. 1st input will be the d.v (X). 2nd input will be the lambda
        /// 4 - is Cauchy. 1st input is the d.v (X). 2nd input is delta (𝜎)
        vector<pair<int, double>> tempContinuous;
        continuousProbabilities = tempContinuous;

        double neededProbFunc = (probabilitySpace == 1) ? pmfFinder() : pdfFinder();
        string typeToOutput = (probabilitySpace == 1) ?  "PMF" : "PDF";

        cout << "The " << typeToOutput << " is: "<< neededProbFunc << endl;
    }

    int findFactorials(int a);

    double pmfFinder();

    double pdfFinder();

    int combimationFinder(double n, double k);

private:
    int probabilitySpace;
    int typeOfProbability;
    vector<double> needed;

    vector<pair<int, double>> discreteProbabilities;
    vector<pair<int, double>> continuousProbabilities;

};


#endif //PROBABILITY_THEORY_CALCULATOR_PDF_H
