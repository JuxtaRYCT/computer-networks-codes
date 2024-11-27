#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void creditBasedFlow(int totalpackets, int initialcredits)
{
    int credits = initialcredits;

    for (int packet = 1; packet <= totalpackets; packet++)
    {
        if (credits > 0)
        {
            cout << "Sending Packet " << packet << " with " << credits << " credits left " << endl;
            credits--;
            this_thread::sleep_for(chrono::seconds(1));
        }
        else
        {
            cout << "No credits left. Waiting for credit replenishment..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            credits = initialcredits;
        }

        cout << "Acknowledgement received for the packet " << packet << "." << endl;
    }
}

int main()
{
    int totalPackets;
    int initialCredits;

    cout << "Enter the total numbner of packets to send: ";
    cin >> totalPackets;
    cout << endl;
    cout << "Enter the intial number of credits:";
    cin >> initialCredits;
    cout << endl;

    creditBasedFlow(totalPackets, initialCredits);
    return 0;
}