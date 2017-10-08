#include  <iostream> 
#include  <ostream> 
#include  <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    //ios_base::app
    //std::ofstream file("rng.txt", std::ofstream::trunc);
   // std::fstream file("rng.txt", ios_base::in);
    //std::fstream file("rng.txt",ofstream::out|ofstream::trunc,0);
    ofstream file("rng.txt");
    for(int i=0; i<=100 ;i++)
    {
    file << i;
    file <<endl;
}
}
