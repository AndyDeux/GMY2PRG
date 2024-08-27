#include <iostream>
#include <vector>

using namespace std;

// Time slots are represented by a data structure: `cas = {number/index of activity, start time, end time}`
struct cas {
    int broj;   // Index of the activity
    int pocetak; // Start time of the activity
    int kraj;    // End time of the activity
};

inline int pocetakCasa(const cas& c)
{
    return c.pocetak;
}

inline int krajCasa(const cas& c)
{
    return c.kraj;
}

// Function to load a list of time slots
vector<cas> ucitajCasove(){
    cout << "Enter the number of activities\n";
    int n;
    cin >> n;
    vector<cas> casovi(n);
    for(int i = 0; i < n; i++){
        cout << "Enter the start and end times for activity " << i+1 << "\n";
        casovi[i].broj = i + 1;  // Initialize the activity number
        int pocetak, kraj;
        cin >> pocetak >> kraj;
        casovi[i].pocetak = pocetak;
        casovi[i].kraj = kraj;
    }
    return casovi;
}

// Function to find the maximum number of non-overlapping activities
int maksBrojCasova(vector<cas>& casovi)
{
    // Get the number of activities
    int n = casovi.size();
    
    // Sort activities based on their end times
    sort(begin(casovi), end(casovi),
         [](const cas& a, const cas& b){
        return krajCasa(a) < krajCasa(b);
    });
    
    // Number of non-overlapping activities
    int brojOdrzanihCasova;
    // End time of the last scheduled activity
    int kraj;
    
    // Schedule the first activity
    brojOdrzanihCasova = 1;
    kraj = krajCasa(casovi[0]);
    
    // Analyze the remaining activities in order of their end times
    for(int i = 1; i < n; i++){
        // If the current activity does not overlap with the last scheduled one
        if(pocetakCasa(casovi[i]) >= kraj){
            // It can be scheduled
            brojOdrzanihCasova++;
            kraj = krajCasa(casovi[i]);
        }
    }
    
    return brojOdrzanihCasova;
}

int main(void)
{
    auto casovi = ucitajCasove();
    cout << "The maximum number of non-overlapping activities is: " << maksBrojCasova(casovi) << endl;
    return 0;
}
