// Coding Assignment 5 - C++ Template

#include <iostream>
#include <iomanip>

using namespace std;


// Step 1: Total counting
long long count_total_strings(int k) {
    long long total = 1;

    for (int i = 0; i < k; i++) {
        total *= 3;
    }

    return total;
}


// Step 2: Count strings with no consecutive identical characters
long long count_no_consecutive_same(int k) {
    long long count = 3;

    for (int i = 1; i < k; i++) {
        count *= 2;
    }

    return count;
}


// Step 3: Probability computation
double prob_no_consecutive_same(int k) {
    return static_cast<double>(count_no_consecutive_same(k)) /
           count_total_strings(k);
}


// Helper function for Step 4:
// Count strings of length k that contain NO "CC"
long long count_no_CC(int k) {
    long long ending_in_C = 1;
    long long ending_in_A_or_B = 2;

    for (int i = 2; i <= k; i++) {
        long long new_ending_in_C = ending_in_A_or_B;
        long long new_ending_in_A_or_B = 2 * (ending_in_C + ending_in_A_or_B);

        ending_in_C = new_ending_in_C;
        ending_in_A_or_B = new_ending_in_A_or_B;
    }

    return ending_in_C + ending_in_A_or_B;
}


// Step 4: Count strings that contain at least one "CC"
long long count_strings_with_CC(int k) {
    return count_total_strings(k) - count_no_CC(k);
}


int main() {

    int k = 5;

    // Optional: basic validity check
    if (k < 1 || k > 20) {
        cout << "Error: k must be between 1 and 20." << endl;
        return 1;
    }

    // Step 1
    long long total_strings = count_total_strings(k);

    // Step 2
    long long no_consecutive_same = count_no_consecutive_same(k);

    // Step 3
    double probability = prob_no_consecutive_same(k);

    // Step 4
    long long with_CC = count_strings_with_CC(k);

    // Output
    cout << "Total Strings = " << total_strings << endl;
    cout << "No Consecutive Same = " << no_consecutive_same << endl;
    cout << fixed << setprecision(4);
    cout << "Probability = " << probability << endl;
    cout << "Strings with \"CC\" = " << with_CC << endl;

    return 0;
}
