#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void goBackN(int totalpackets, int windowSize)
{
    int nextPacket = 1;

    while (nextPacket <= totalpackets)
    {
        for (int i = 0; i < windowSize && nextPacket + i <= totalpackets; i++)
        {
            cout << "Sending Packets " << nextPacket + i << "..." << endl;
        }

        for (int i = 0; i < windowSize && nextPacket + i <= totalpackets; i++)
        {
            int ack = rand() % 2;
            if (ack == 1)
            {
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Acknowledgement received for packet " << nextPacket + i << "." << endl;
            }
            else
            {
                cout << "Acknowledgement lost for packet " << nextPacket + i << "Retransmitting Window..." << endl;
                break;
            }
        }
        nextPacket += windowSize;
    }
}

int main()
{
    srand(time(0));
    int totalPackets;
    int windowSize;
    cout << "Enter the total number of packets to send:";
    cin >> totalPackets;
    cout << "window: ";

    cin >> windowSize;

    goBackN(totalPackets, windowSize);
}