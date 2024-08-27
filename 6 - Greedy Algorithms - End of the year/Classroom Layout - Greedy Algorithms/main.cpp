#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

// Structure to represent an event
struct dogadjaj {
    int ime;       // Identifier for the event
    int pocetak;   // Start time of the event (in minutes from midnight)
    int zavrsetak; // End time of the event (in minutes from midnight)
};

// Function prototypes
void ucitajPodatke(vector<dogadjaj> &);
void rasporedPoUcionicama(vector<dogadjaj> &, vector<vector<dogadjaj>> &);
bool uporedi(dogadjaj &, dogadjaj &);
bool ubaciUUcionicu(dogadjaj &, vector<vector<dogadjaj>> &);
void kreirajNovuUcionicu(dogadjaj &, vector<vector<dogadjaj>> &);
void prikaziRaspored(vector<vector<dogadjaj>> &);

int main(void)
{
    vector<dogadjaj> spisak;               // List of events
    vector<vector<dogadjaj>> raspored;    // Schedule (a list of lists of events)
    
    ucitajPodatke(spisak);                // Load events from file
    
    sort(spisak.begin(), spisak.end(), uporedi);  // Sort events by start time
    
    rasporedPoUcionicama(spisak, raspored);      // Schedule events into classrooms
    
    prikaziRaspored(raspored);                  // Display the schedule
    
    return 0;
}

// Function to load events from a file
void ucitajPodatke(vector<dogadjaj> &s)
{
    ifstream ulaz;
    ulaz.open("./ulaz.txt");
    
    if (!ulaz.is_open())
        return;
    
    int oznaka = 0;      // Event identifier
    int start, kraj;    // Start and end times
    int cas, minut;     // Hours and minutes
    dogadjaj podatak;   // Temporary variable to store event data
    
    while (!ulaz.eof())
    {
        ulaz >> cas >> minut;
        start = cas * 60 + minut;  // Convert start time to minutes from midnight
        ulaz >> cas >> minut;
        kraj = cas * 60 + minut;   // Convert end time to minutes from midnight
        
        podatak.ime = oznaka++;    // Assign identifier
        podatak.pocetak = start;
        podatak.zavrsetak = kraj;
        
        s.push_back(podatak);    // Add event to the list
    }
    
    ulaz.close();
}

// Comparator function to sort events by start time
bool uporedi(dogadjaj &prvi, dogadjaj &drugi)
{
    return prvi.pocetak < drugi.pocetak;
}

// Function to schedule events into existing classrooms
void rasporedPoUcionicama(vector<dogadjaj> &s, vector<vector<dogadjaj>> &r)
{
    for (auto &a : s)
        if (!ubaciUUcionicu(a, r))   // Try to add event to an existing classroom
            kreirajNovuUcionicu(a, r);  // Create a new classroom if needed
}

// Function to try to add an event to an existing classroom
bool ubaciUUcionicu(dogadjaj &a, vector<vector<dogadjaj>> &r)
{
    dogadjaj p; // Temporary variable
    
    for (auto &vp : r)   // Iterate through existing classrooms
    {
        p = vp.back();   // Get the last event in the current classroom
        if (p.zavrsetak <= a.pocetak)  // Check if the event can fit in this classroom
        {
            vp.push_back(a);  // Add the event to the classroom
            return true;      // Successfully added
        }
    }
    
    return false;   // Failed to add the event to any existing classroom
}

// Function to create a new classroom for an event
void kreirajNovuUcionicu(dogadjaj &a, vector<vector<dogadjaj>> &r)
{
    vector<dogadjaj> novaProstorija;  // New classroom
    novaProstorija.push_back(a);      // Add the event to the new classroom
    r.push_back(novaProstorija);      // Add the new classroom to the schedule
}

// Function to display the schedule
void prikaziRaspored(vector<vector<dogadjaj>> &r)
{
    unsigned int brojac = 0;    // Classroom index
    
    for (auto &vp : r)
    {
        cout << "\nClassroom " << brojac++ << endl;
        
        for (auto &d : vp)  // Iterate through events in the classroom
        {
            cout << setw(8) << d.ime; // Event identifier
            cout << setw(8) << d.pocetak / 60 << ":";  // Start time (hours)
            cout << setw(2) << d.pocetak % 60;         // Start time (minutes)
            cout << setw(8) << d.zavrsetak / 60 << ":"; // End time (hours)
            cout << setw(2) << d.zavrsetak % 60 << endl; // End time (minutes)
        }
    }
}
