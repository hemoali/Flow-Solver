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
int main(int argc, char** argv) {
    boostIO();

    float screenWidth = atof(argv[1]);
    float screenHeight = atof(argv[2]);
    float screenWDPI = atof(argv[3]);
    float screenHDPI = atof(argv[4]);
    
    
    int startTime = clock();
    
    try {
        FlowSolver solver("game.png");
        solver.printMaze();
        solver.solve();
        string solution = solver.getSolutionPaths();
        cout << "Instructions: " << solution << endl;
        
        // Calculate grid block size in CMs
        float blockSize = solver.singleBlockWidth;

        blockSize = ( blockSize / screenWDPI ) * 2.54;

        int blockSizeIntegerPart = (blockSize);
        int blockSizeFractionalPart = (blockSize - blockSizeIntegerPart) * 100000000;
        
        // Output to file
        ofstream fout("Path.txt");
        fout << blockSizeIntegerPart<< " ";
        fout << blockSizeFractionalPart << " ";
        fout << solution;
        fout.close();
    }
    catch (const exception& ex) {
        cout << "ERROR::" << ex.what() << endl;
    }
    
    int stopTime = clock();
    cout << endl << "Time: " << (stopTime - startTime) / double(CLOCKS_PER_SEC) * 1000.0 << "ms" << endl;
    
    return 0;
}
