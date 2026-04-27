#include <iostream>

static const std::string names[] = {
    "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

int main() {
    // Init and read input vars.
    int a, b;
    std::cin >> a >> b;
    
    for (int i = a; i < b+1; i++){
        // Print number in English if it's <= 9.
        if (i <= 9){
            std::cout << names[i-1] << std::endl;
            continue;
        }
        
        // If the number > 9, then print its parity.
        std::cout << (i % 2 == 0 ? "even" : "odd") << std::endl;
    }
}
