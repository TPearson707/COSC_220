/*
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/25/2023
 * Date of Last Update: 11/30/2023
 * Description: Test program that runs a simulation to test how different amount of cpu cores handle different loads
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "PriorityQueue.h"
#include "Process.h"

using namespace std;


void setSimulationSettings(int & cpuCores, int & minExeCycles, int & maxExeCycles, int & prioLevel, float & minimumNumberOfNewPer, float & maximumNumberOfNewPer, float & processes, int & length);

void pushHeaderToCsv(ofstream &);
void pushToCsv(float, int, int, int, int, int , int, int, ofstream &);

int main() {
    int totalCpuCores = 0; // the total number of cpu cores that will be used in the sim
    int minimumExecutionCycles = 0; // the minimum number of execution cycles to complete a process in our cpu
    int maximumExecutionCycles = 0; // the maximum number of execution cycles to complete a process in our cpu
    int totalPriorityLevels = 0; // the total number of priority levels for our queue
    float minimumNumberOfNewPer = 0;
    float maximumNumberOfNewPer = 0;
    float processesPerCycle = 0.0; // this is the number of processes that can happen per cycle 1 process = 1 process per cycle
    int simulationLength = 0; // the length of our simulation

    setSimulationSettings(totalCpuCores, minimumExecutionCycles, maximumExecutionCycles, totalPriorityLevels, minimumNumberOfNewPer, maximumNumberOfNewPer, processesPerCycle, simulationLength);

    PriorityQueue<Process> queue;

    int cpu[totalCpuCores]; // the array that will take in completed processes into the cpu

    int processesExecuted = 0; // this is a counter of the number of processes that were executed
    int totalWaitTime = 0; // the total wait time for each process
    int processesRemainingInQueue = 0; // the processes that have not been executed by the end of the simulation
    int totalExecutionTimeForUnfinished = 0; // the total time it would take to execute the rest of the processes
    unsigned long int totalWaitTimeForUnfinished = 0; // the total wait time for the unfinished processes
    long maxWaitTimeUnprocessed = 0;
    int idleTime = 0; // variable to represent idle time when a cpu core is waiting for a process
    float newProcessAmount = 0;

    ofstream outFile("Simulation2(4).csv");

    if (outFile.is_open()) {
        pushHeaderToCsv(outFile);
    } else {
        cout << "ERROR: Failed to open file" << endl;
        exit(1);
    }

    while (minimumNumberOfNewPer <= maximumNumberOfNewPer) {

        for (int cycle = 0; cycle < simulationLength; cycle++) {

            // while newProcessesAmount is greater than or == to one we're going to add a new Process to the queue
            // and decrement newProcessAmount
            newProcessAmount += minimumNumberOfNewPer; // 4. Add in a new process

            while (newProcessAmount >= 1) {
                int exeTime = rand() % (maximumExecutionCycles - (minimumExecutionCycles - 1)) + minimumExecutionCycles;
                int priority = rand() % totalPriorityLevels + 1;

                Process newProcess(exeTime, cycle);

                queue.enqueue(newProcess, priority);
                newProcessAmount -= 1;
            }


            // in this loop we're checking to see if an index in our cpu is empty, if it is we'll dequeue a process nad put it in the cpu
            // to be executed
            for (int core = 0; core < totalCpuCores; core++) { // 1. accept another process

                if (!cpu[core] && !queue.isEmpty()) {
                    Process currentProcess;

                    currentProcess = queue.dequeue();
                    cpu[core] = currentProcess.getExeTime();
                    totalWaitTime += cycle - currentProcess.getTimeStamp();
                    processesExecuted++;
                    continue;
                }

            }

            // if a cpu core is waiting for a value increment idle time
            for (int core = 0; core < totalCpuCores; core++) // 2. increment idle time
                if (!cpu[core]) // If a there is no process increment
                    idleTime++;

            // if there is a value in our cpu we decrement each value
            for (int core = 0; core < totalCpuCores; core++) // 3. decement the values of each cpu core that is executing a process
                if (cpu[core])
                    cpu[core]--; // if there is a process decrement


        }

        // total execution time for unfinished
        for (int i = 0; i < queue.size(); i++)
            totalExecutionTimeForUnfinished += queue[i].getExeTime();

        // processes remaining
        processesRemainingInQueue = queue.size();

        int cycleCounter = simulationLength; // this will act as an itterator for our while loop
        // get total wait time for the unfinished processes
        while(queue.size() > 0) {

                if (maxWaitTimeUnprocessed < simulationLength)
                    maxWaitTimeUnprocessed++;

            for (int core = 0; core < totalCpuCores; core++) {

                if (!cpu[core]) {
                    Process currentProcess;

                    currentProcess = queue.dequeue();
                    cpu[core] = currentProcess.getExeTime();

                    totalWaitTimeForUnfinished += cycleCounter - currentProcess.getTimeStamp();
                    continue;
                }
            }

            for (int core = 0; core < totalCpuCores; core++)
                if (cpu[core])
                    cpu[core]--;

            cycleCounter++;
        }

        pushToCsv(minimumNumberOfNewPer, idleTime, processesExecuted, totalWaitTime, processesRemainingInQueue, totalExecutionTimeForUnfinished, totalWaitTimeForUnfinished, maxWaitTimeUnprocessed, outFile);

        queue.clear();

        for (int i = 0; i < totalCpuCores; i++)
            cpu[i] = 0;


        processesExecuted = 0; // this is a counter of the number of processes that were executed
        totalWaitTime = 0; // the total wait time for each process
        processesRemainingInQueue = 0; // the processes that have not been executed by the end of the simulation
        totalExecutionTimeForUnfinished = 0; // the total time it would take to execute the rest of the processes
        totalWaitTimeForUnfinished = 0; // the total wait time for the unfinished processes
        idleTime = 0; // variable to represent idle time when a cpu core is waiting for a process
        newProcessAmount = 0;
        maxWaitTimeUnprocessed = 0;
        minimumNumberOfNewPer += processesPerCycle;
    }

    outFile.close();

    return 0;
}

/*
 * Description: This function is used to set the setting sfor the simulation
 * Parameters: int & cpuCores, int & minExeCycles, int & maxExeCycles, int & prioLevel, float & processes, int & length
 * Return Type: None
 */
void setSimulationSettings(int & cpuCores, int & minExeCycles, int & maxExeCycles, int & prioLevel, float & minimumNumberOfNewPer, float & maximumNumberOfNewPer, float & processes, int & length) {

    cout << "Input the Number of CPU Cores: ";
    cin >> cpuCores;

    cout << "Input the Minimum Number of Execution Cycles per Process: ";
    cin >> minExeCycles;

    cout <<"Input the Maximum Number of Execution Cycles per Process: ";
    cin >> maxExeCycles;

    cout << "Input the Number of Priority Levels: ";
    cin >> prioLevel;

    cout << "Minimum Number of New Processes per Cycle: ";
    cin >> minimumNumberOfNewPer;

    cout << "Maximum Number of New Processes per Cycle: ";
    cin >> maximumNumberOfNewPer;

    cout << "Input the Number of New Processes per Cycle: ";
    cin >> processes;

    cout << "Input the Length of the Simulation in Cycles: ";
    cin >> length;

}

/*
 * Description: This function will push the header of the simulation into a csv file using an ofstream object
 * Parameters: ofstream & outFile
 * Return Type: None
 */
void pushHeaderToCsv(ofstream & outFile) {
    outFile << "Load,Idle,Completed,Processes Wait,Unprocessed,Exe. Needed,Unpro. Wait,Unpr. Max. Wait" << endl;
}

/*
 * Description: This function will push the data from each simulation that was ran with x load into a csv file
 * Parameters: float load, int idleTime, int processesExecuted, int totalWaitTime, int processesRemainingInQueue, int totalExecutionTimeForUnfinished, int totalWaitTimeForUnfinished, int maxWaitTimeUnprocessed, ofstream & outFile
 * Return Type: None
 */
void pushToCsv(float load, int idleTime, int processesExecuted, int totalWaitTime, int processesRemainingInQueue, int totalExecutionTimeForUnfinished, int totalWaitTimeForUnfinished, int maxWaitTimeUnprocessed, ofstream & outFile) {
    outFile << load << "," << idleTime << "," << processesExecuted << "," << totalWaitTime << "," << processesRemainingInQueue << "," << totalExecutionTimeForUnfinished << "," << totalWaitTimeForUnfinished << "," << maxWaitTimeUnprocessed << endl;
}
