#include <iostream>
#include <vector>
#include "pdf.h"

using namespace std;

int main() {
    /// if 1 then discrete, if 2 then continuous
    int probabilitySpace;
    /// discrete probs
    vector<string> typesOfDiscrete = {"Uniform", "Bernoulli", "Binomial", "Poisson", "Geometric"};
    /// continuous probs
    vector<string> typesOfContinuous = {"Uniform", "Normal", "Exponential", "Cauchy"};
    int typeOfDistribution;


    cout << "Discrete or continuous? (Please enter (1) for discrete and (2) for continuous)" << endl;
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

    cout << "Please enter the parameters that are needed for the distribution: " << endl;

    vector<double> parameters;

    if (probabilitySpace == 1) {
        /// uniform
        if (typeOfDistribution == 1) {
            double a;
            cout << "Please enter the size of the Uniform Distribution: ";
            cin >> a;
            parameters.push_back(a);
        }
        /// bernouli
        else if (typeOfDistribution == 2) {
            double a;
            cout << "Please enter the probability of success: ";
            cin >> a;
            parameters.push_back(a);
        }
        /// binomial
        else if (typeOfDistribution == 3) {
            double a, b, c;
            cout << "Please enter amount of wins: ";
            cin >> a;
            parameters.push_back(a);
            cout << "Please enter amount of tries: ";
            cin >> b;
            parameters.push_back(b);
            cout << "Please enter the probability of success: ";
            cin >> c;
            parameters.push_back(c);        }
        /// pois
        else if (typeOfDistribution == 4){
            double a, b;
            cout << "Please enter the x: ";
            cin >> a;
            parameters.push_back(a);            cout << "Please enter the lambda: ";
            cin >> b;
            parameters.push_back(b);
        }
        /// geometrical
        else {
            double a, b;
            cout << "Please enter the x: ";
            cin >> a;
            parameters.push_back(a);
            cout << "Please enter the p: ";
            cin >> b;
            parameters.push_back(b);
        }
    }

    pdf probabilityFunction(probabilitySpace ,typeOfDistribution, parameters);

    return 0;
}
