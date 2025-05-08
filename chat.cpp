#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string getResponse(string userInput) {
    string input = toLower(userInput);

    if (input.find("hello") != string::npos || input.find("hi") != string::npos) {
        return "ElectroBot: Hello! How can I assist you today?";
    } else if (input.find("store hours") != string::npos || input.find("timing") != string::npos) {
        return "ElectroBot: Our store is open from 9 AM to 9 PM, Monday to Saturday.";
    } else if (input.find("return policy") != string::npos || input.find("return") != string::npos) {
        return "ElectroBot: You can return products within 7 days with the original bill.";
    } else if (input.find("available") != string::npos || input.find("stock") != string::npos) {
        return "ElectroBot: Please mention the product name, and I'll check availability.";
    } else if (input.find("thank") != string::npos) {
        return "ElectroBot: You're welcome!";
    } else if (input == "exit") {
        return "exit";
    } else {
        return "ElectroBot: I'm sorry, I didn't understand that. Could you please rephrase?";
    }
}

int main() {
    cout << "ElectroBot: Hello! I'm ElectroBot, your customer assistant.\n";
    cout << "Type 'exit' to end the conversation.\n\n";

    string userInput;
    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        string botResponse = getResponse(userInput);

        if (botResponse == "exit") {
            cout << "ElectroBot: Thank you! Have a great day!\n";
            break;
        }

        cout << botResponse << "\n\n";
    }

    return 0;
}
