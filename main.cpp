#include "Lab12ModeAModeB.h"
#include <QtWidgets/QApplication>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "Service.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository* mainRepo;
    Repository* myList;
    std::string configuration;
    ifstream file;
    file.open("C:\\Users\\PC\\source\\repos\\Lab12ModeAModeB\\Config.txt");
    std::string line;
    getline(file, line);
    smatch matchFound;
    regex inMemory("memory");
    regex html("html");
    regex csv("csv");
    if (regex_search(line, matchFound, inMemory))
        mainRepo = new InMemoryRepo{};
    else
        mainRepo = new FileRepository{};
    getline(file, line);
    if (regex_search(line, matchFound, inMemory))
        myList = new MemoryRepoWatchman{};
    else
    {
        if (regex_search(line, matchFound, html))
            myList = new HtmlRepository{};
        else
            myList = new CsvRepository{};
    }
    Service service{ mainRepo, myList };

    Lab12ModeAModeB w{ service };
    w.show();
    return a.exec();
}
