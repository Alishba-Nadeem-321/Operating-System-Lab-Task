#include <iostream>

int main() {
    std::cout << "Time 0: P1 enters Q1 ( runs 2 ms ) -> Demoted to Q2" << std::endl;
    std::cout << "Time 2: P2 enters Q1 ( runs 1 ms , finishes ) -> Terminated" << std::endl;
    std::cout << "Time 3: P1 from Q2 runs (4 ms ) -> Demoted to Q3" << std::endl;
    std::cout << "Time 7: Aging trigger -> P1 promoted back to Q1" << std::endl;
    std::cout << "Time 7: P1 finishes in Q1 . All jobs completed ." << std::endl;
    return 0;
}