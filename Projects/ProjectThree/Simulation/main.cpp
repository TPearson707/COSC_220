/*
 * Name of Author: Thomas Pearson
 * Date of Creation: 11/25/2023
 * Date of Last Update: 11/25/2023
 * Description: Test program that runs a simulation to test how different amount of cpu cores handle different loads
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

/*
 * Description: This function is used to set the setting sfor the simulation
 * Parameters: int & cpuCores, int & minExeCycles, int & maxExeCycles, int & prioLevel, float & processes, int & length
 * Return Type: None
 */
void setSimulationSettings(int & cpuCores, int & minExeCycles, int & maxExeCycles, int & prioLevel, float & processes, int & length);

/*
 * Description: This function will display the final results of a simulation
 * Parameters:  int idleTime, int processesExe, int totalWait, int processesRemaining, int exeTimeNeeded, int totalWaitUnfinished, int maxWaitUnfinished
 * Return Type: None
 */
void displayResults(int idleTime, int processesExe, int totalWait, int processesRemaining, int exeTimeNeeded, int totalWaitUnfinished, int maxWaitUnfinished);


int main() {
    int totalCpuCores = 0; // the total number of cpu cores that will be used in the sim
    int minimumExecutionCycles = 0; // the minimum number of execution cycles to complete a process in our cpu
    int maximumExecutionCycles = 0; // the maximum number of execution cycles to complete a process in our cpu
    int totalPriorityLevels = 0; // the total number of priority levels for our queue
    float processesPerCycle = 0.0; // this is the number of processes that can happen per cycle 1 process = 1 process per cycle
    int simulationLength = 0; // the length of our simulation

    setSimulationSettings(totalCpuCores, minimumExecutionCycles, maximumExecutionCycles, totalPriorityLevels, processesPerCycle, simulationLength);

    PriorityQueue<Process> queue;

    int cpu[totalCpuCores]; // the array that will take in completed processes into the cpu

    int processesExecuted = 0; // this is a counter of the number of processes that were executed
    int totalWaitTime = 0; // the total wait time for each process
    int processesRemainingInQueue = 0; // the processes that have not been executed by the end of the simulation
    int totalExecutionTimeForUnfinished = 0; // the total time it would take to execute the rest of the processes
    unsigned long int totalWaitTimeForUnfinished = 0; // the total wait time for the unfinished processes

int idleTime = 0;
float newProcessAmount = 0;

    for (int cycle = 0; cycle < simulationLength; cycle++) {

        // while newProcessesAmount is greater than or == to one we're going to add a new Process to the queue
        // and decrement newProcessAmount
        newProcessAmount += processesPerCycle; // 4. Add in a new process

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

    int cycleCounter = 0; // this will act as an itterator for our while loop

    // get total wait time for the unfinished processes
    while(queue.size() > 0) {

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


    displayResults(idleTime, processesExecuted, totalWaitTime, processesRemainingInQueue, totalExecutionTimeForUnfinished, totalWaitTimeForUnfinished, simulationLength);

    return 0;
}

void setSimulationSettings(int & cpuCores, int & minExeCycles, int & maxExeCycles, int & prioLevel, float & processes, int & length) {

    cout << "Input the Number of CPU Cores: ";
    cin >> cpuCores;

    cout << "Input the Minimum Number of Execution Cycles per Process: ";
    cin >> minExeCycles;

    cout <<"Input the Maximum Number of Execution Cycles per Process: ";
    cin >> maxExeCycles;

    cout << "Input the Number of Priority Levels: ";
    cin >> prioLevel;

    cout << "Input the Number of New Processes per Cycle: ";
    cin >> processes;

    cout << "Input the Length of the Simulation in Cycles: ";
    cin >> length;

}

void displayResults(int idleTime, int processesExe, int totalWait, int processesRemaining, int exeTimeNeeded, int totalWaitUnfinished, int maxWaitUnfinished) {

    cout << "============ Simulation Results ============" << endl;

    cout << "Idle Time: " << idleTime << endl;

    cout << "Processes Completed = " << processesExe << endl;

    cout << "Total Wait Time of Completed Processes = " << totalWait << endl;

    cout << "Number of Processes Remaining in Queue = " << processesRemaining << endl;

    cout << "Total Execution Time Needed for Unprocessed Processes = " << exeTimeNeeded << endl;

    cout << "Total Wait Time for Unprocessed Processes = " << totalWaitUnfinished << endl;

    cout << "Maxmimum Wait Time for Unprocessed Processes = " << maxWaitUnfinished << endl;

}
