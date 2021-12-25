#include <iostream>
#include <vector>
#include "pdf.h"
#include "expected_val.h"
#include "variance.h"

using namespace std;

int main() {
    /// if 1 then discrete, if 2 then continuous
    int probabilitySpace;
    /// discrete probs
    vector<string> typesOfDiscrete = {"Uniform", "Bernoulli", "Binomial", "Poisson", "Geometric"};
    /// continuous probs
    vector<string> typesOfContinuous = {"Uniform", "Normal", "Exponential", "Cauchy"};
    int typeOfDistribution;


    cout << "Discrete or continuous? (Please enter (1) for discrete and (2) for continuous): ";
    cin >> probabilitySpace;

    if (probabilitySpace > 2 || probabilitySpace < 1) {
        cout << "No such probability space please relaunch the program thanks!" << endl;
        return 0;
    }

    /// here we know with what prob space that we are working with (discrete or continuous)
    vector<string> probabilitySpaceChoice = (probabilitySpace == 1) ? typesOfDiscrete : typesOfContinuous;

    string typeToOutput = (probabilitySpace == 1) ?  "discrete" : "continuous";
    cout << "Please select the type of " << typeToOutput << " distribution (Press the number beside the distribution):" << endl;

    int choice = 1;
    for (const auto &el : probabilitySpaceChoice) {
        cout << el << " - " << choice << endl;
        choice += 1;
    }

    cin >> typeOfDistribution;

    cout << "Please enter the that are needed for the distribution: " << endl;

    vector<double> parametersProbFunction;
    vector<double> parametersExpectedValue;
    vector<double> parametersVariance;


    if (probabilitySpace == 1) {
        /// uniform
        if (typeOfDistribution == 1) {
            double a;
            cout << "Please enter the size of the Uniform Distribution: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            parametersExpectedValue.push_back(a);
            parametersVariance.push_back(a);
        }
        /// bernouli
        else if (typeOfDistribution == 2) {
            double a;
            cout << "Please enter the probability of success: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            parametersExpectedValue.push_back(a);
            parametersVariance.push_back(a);
        }
        /// binomial
        else if (typeOfDistribution == 3) {
            double a, b, c;
            cout << "Please enter amount of wins: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            cout << "Please enter amount of tries: ";
            cin >> b;
            parametersExpectedValue.push_back(b);
            parametersProbFunction.push_back(b);
            parametersVariance.push_back(b);
            cout << "Please enter the probability of success: ";
            cin >> c;
            parametersProbFunction.push_back(c);
            parametersExpectedValue.push_back(c);
            parametersVariance.push_back(c);
        }
        /// pois
        else if (typeOfDistribution == 4){
            double a, b;
            cout << "Please enter the x: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            cout << "Please enter the lambda: ";
            cin >> b;
            parametersProbFunction.push_back(b);
            parametersExpectedValue.push_back(b);
            parametersVariance.push_back(b);
        }
        /// geometrical
        else {
            double a, b;
            cout << "Please enter the x: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            cout << "Please enter the p: ";
            cin >> b;
            parametersProbFunction.push_back(b);
            parametersExpectedValue.push_back(b);
            parametersVariance.push_back(b);
        }
    }

    if (probabilitySpace == 2) {
        /// uniform
        if (typeOfDistribution == 1) {
            double a, b, c;
            cout << "Please enter the start of the segment: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            parametersExpectedValue.push_back(a);
            parametersVariance.push_back(a);
            cout << "Please enter the end of the segment: ";
            cin >> b;
            parametersExpectedValue.push_back(b);
            parametersProbFunction.push_back(b);
            parametersVariance.push_back(b);
            cout << "Please enter the start random variable: ";
            cin >> c;
            parametersProbFunction.push_back(c);
        }
        /// normal
        else if (typeOfDistribution == 2) {
            double a, b, c;
            cout << "Please enter the random variable: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            cout << "Please enter the a: ";
            cin >> b;
            parametersProbFunction.push_back(b);
            parametersExpectedValue.push_back(b);
            cout << "Please enter delta squared: ";
            cin >> c;
            parametersProbFunction.push_back(c);
            parametersVariance.push_back(c);
        }
        /// exp
        else if (typeOfDistribution == 3) {
            double a, b;
            cout << "Please enter the random variable: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            cout << "Please enter the lambda: ";
            cin >> b;
            parametersProbFunction.push_back(b);
            parametersExpectedValue.push_back(b);
            parametersVariance.push_back(b);
        }
        /// Cauchy
        else {
            double a, b;
            cout << "Please enter the random variable: ";
            cin >> a;
            parametersProbFunction.push_back(a);
            cout << "Please enter the delta: ";
            cin >> b;
            parametersProbFunction.push_back(b);
        }
    }

    cout << "------------------------------------------------------------------------------------------------" << endl;

    pdf probabilityFunction(probabilitySpace ,typeOfDistribution, parametersProbFunction);
    expected_val expectedValue(probabilitySpace ,typeOfDistribution, parametersExpectedValue);
    variance variance(probabilitySpace ,typeOfDistribution, parametersVariance);


    return 0;
}
