#include <iostream>
#include <vector>

using namespace std;

int main() {
    /// if 1 then discrete, if 2 then continuous
    int probabilitySpace;
    /// discrete probs
    vector<string> typesOfDiscrete = {"Uniform", "Bernoulli", "Binomial", "Poisson", "Geometric"};
    /// continuous probs
    vector<string> typesOfContinuous = {"Uniform", "Normal", "Gamma", "Exponential", "Cauchy"};
    int typeOfProbability;
    int typeOfDistribution;


    cout << "Discrete or continuous? (Please enter (1) for discrete and (2) for continuous)" << endl;
    cin >> probabilitySpace;

    /// here we know with what prob space that we are working with (discrete or continuous)
    vector<string> probabilitySpaceChoice = (probabilitySpace == 1) ? typesOfDiscrete : typesOfContinuous;

    string a = (probabilitySpace == 1) ?  "discrete" : "continuous";
    cout << "Please select the type of " << a << " distribution (Press the number beside the distribution):" << endl;

    int choice = 1;
    for (const auto &el : probabilitySpaceChoice) {
        cout << el << " - " << choice << endl;
        choice += 1;
    }

    cin >> typeOfDistribution;

    return 0;
}
