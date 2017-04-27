#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "FlowSolver.h"
using namespace std;

/**
 * Used to boost reading/writing from/to the console
 */
inline void boostIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

/**
 * Main function
 */
int main() {
    boostIO();
    
    try {
        FlowSolver solver("/Users/ibrahimradwan/Development/puzzlesolver/puzzlesolver/game.png");
        solver.solve();
        string solution = solver.getSolutionPaths();
        ofstream fout("Path.txt");
        fout << solution;
        fout.close();
    }
    catch (const exception& ex) {
        cout << "ERROR::" << ex.what() << endl;
    }
    return 0;
}
