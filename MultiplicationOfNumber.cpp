#include <iostream>
#include <fstream>

using namespace std;

// User Infomation
class UserInfo {
    private:

    // initialization
     string userData[11] = {
                                "Title (Mr, Mrs,Ms)",
                                "First Name",
                                "Middle Name",
                                "Last Name",
                                "Age",
                                "Gender (Male/ Female)",
                                "Height",
                                "Phone No or Email Address (09-1234, someone@mail.com)",
                                "Address (Eg. Yangon, Mandalay, Ayyarwaddy)",
                                "Uni Name (Eg. UIT, YTU, HBTU, TTU, WYTU)",
                                "Uni Major (Eg. Civil, Archi, EC, MC, ME, IT)"

                                };

        string userInput[11];
         int infoNo = 10;

    public:
    UserInfo () {
        int i = 0;
       
        while(i <= infoNo)
        {
            cout << "Enter your " << userData[i] << "! \n";
            cin >> userInput[i];
            i++;
        }
    }

    void userInfo_Method () {

        // Create a file for User_Info
        ofstream userInputInfoFile("UserInfoFile.txt");

        // Write file
        userInputInfoFile << "\n \n Results: " << endl
                << "Your Name: " + userInput[0] + ". " + userInput[1] + " " + userInput[2] + " " + userInput[3] << endl
                << "Age: " + userInput[4] << endl
                << "Gender: " + userInput[5] << endl
                << "Height: " + userInput[6] << endl
                << "Phone No: " + userInput[7] << endl
                << "Address: " + userInput[8] << endl
                << "Uni Name: " + userInput[9] << endl
                << "Uni Major: " + userInput[10] << endl;

        userInputInfoFile.close();
    }

    private:
    void dataOutput () {

        // Interface section
        cout << "\n \n Results: " << endl
                << "Your Name: " + userInput[0] + ". " + userInput[1] + " " + userInput[2] + " " + userInput[3] << endl
                << "Age: " + userInput[4] << endl
                << "Gender: " + userInput[5] << endl
                << "Height: " + userInput[6] << endl
                << "Phone No: " + userInput[7] << endl
                << "Address: " + userInput[8] << endl
                << "Uni Name: " + userInput[9] << endl
                << "Uni Major: " + userInput[10] << endl;
    }

    public:
    void Interface_DataOutput () {
        dataOutput();
    }

};

 // Initialize Another Class for Calculation
class MyCalculate_Program {

    public:
    string number = "_";
    int inputNumber;
    
    // a Constructor
    MyCalculate_Program () {

        // Create file for Calculation
        ofstream calculateFile("Calculate.txt");

        // Write file
        for (int i = 1; i <= 12; i++) {
            calculateFile << number << " * " << i << ": " << endl;
        }

        calculateFile.close();
    }

    // Overwrite file with User_Input Number
    void OverWriteFile_Method () {

        cout << "Enter Number: ";
        cin >> inputNumber;
        
        ofstream inputCalculateFile("Calculate.txt");

        // OverWrite file
        for (int i = 1; i <= 12; i++) {
            inputCalculateFile <<  inputNumber << " * " << i << ": " << endl;
        }

        inputCalculateFile.close();
    }

    void CalculateResult() {
        
        // Call an earlier function
        OverWriteFile_Method();

        ifstream readCalculateFile("Calculate.txt");
        string calculateText;

        string storedWriteFile[12];
        int userInputAnswer[12];
        int i = 0;
        while(getline(readCalculateFile, calculateText))
        {
            storedWriteFile[i] = calculateText;
            i++;
        }

        readCalculateFile.close();

        int resultNumber;
        int j = 0;
        int ArrayLength = 12;
        int saveInputData[12];

        while (j < ArrayLength) 
        {
            cout << storedWriteFile[j];
            cin >> userInputAnswer[j];

            do
            {
                if(userInputAnswer[j] == inputNumber*(j+1)){

                    for (int k = 0; k < ArrayLength; k++)
                    {
                        saveInputData[k] = userInputAnswer[k];
                    }
                    

                } else {
                    cout << storedWriteFile[j];
                    cin >> userInputAnswer[j];
                }

            } while (userInputAnswer[j] != inputNumber*(j+1));
                j++;
            
            
        }

        // Create and Write result file
        ofstream resultFile("Result.txt");
        int z = 0;
        while(z < 12)
        {
            resultFile << storedWriteFile[z] << saveInputData[z] << endl;
            z++;
        }
        resultFile.close();
    }

};

class FinalResult {
    public:

    FinalResult () {
        MyCalculate_Program calculateProgram;
        calculateProgram.CalculateResult();
    }
};

int main () {
    UserInfo userInfo;
    userInfo.userInfo_Method();
    userInfo.Interface_DataOutput();

    FinalResult result;

    return 0;
}
