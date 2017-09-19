#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile("links.txt");
    if(!infile) std::cerr << "can not open file";
    ofstream outfile("format.csv");
    if(!outfile) std::cerr << "can not create file";

    istringstream is;
    ostringstream os;

    string line;
    while(!infile.eof()) {
        string url, user, date, sign;
        infile >> url >> user >> date >> sign;   //获取字段值
        line = url + "," + user + "," + date + "," + sign;  //格式化每行写入文件格式
        outfile << line << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
