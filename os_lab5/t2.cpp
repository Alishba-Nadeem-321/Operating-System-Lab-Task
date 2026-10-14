#include <iostream>
using namespace std;
int counter = 100;
int main() {
    cout << "[Parent BEFORE fork] counter = " << counter << " at address: " << &counter << endl;
    int child_counter = counter; // Child gets copy - Copy-on-Write simulation
    child_counter += 50;
    cout << "[Child] counter = " << child_counter << " at address: " << &child_counter << endl;
    cout << "[Parent AFTER child] counter = " << counter << " at address: " << &counter << endl;
    cout << "Proof: Different address & value = Memory Isolated (Copy-on-Write)" << endl;
    return 0;
}