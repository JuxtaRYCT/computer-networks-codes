#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
// Simulates the Stop-and-Wait protocol for flow control
void stopAndWait(int totalPackets)
{
    for (int packet = 1; packet <= totalPackets; ++packet)
    {
        cout << "Sending packet " << packet << "..." << endl;
        // Simulate random acknowledgment loss or delay
        int ack = rand() % 2;
        // If ack = 1, the acknowledgment is received; else, it's lost.
        if (ack == 1)
        {
            // Simulate transmission delay
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Acknowledgment received for packet " << packet << "." << endl;
        }
        else
        {
            // Simulate lost acknowledgment; retransmit the packet
            cout << "Acknowledgment lost for packet " << packet << ". Retransmitting..." << endl;
            packet--; // Retransmit the packet
        }
        // Simulate delay between packet transmissions
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    srand(time(0)); // Initialize random seed for acknowledgment loss simulation
    int totalPackets;
    // Input: Total number of packets to send
    cout << "Enter the total number of packets to send: ";
    cin >> totalPackets;
    // Simulate the Stop-and-Wait protocol
    stopAndWait(totalPackets);
    return 0;
}