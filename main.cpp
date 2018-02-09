#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

FILE *input;
FILE *output;

input = fopen("NBA.csv", "r");
   if (input == nullptr){
     cout << "Could not open file" << endl;
     return -1;
  }
output = fopen("nba_db", "wb");
if (output == nullptr){
     cout << "Could not create output file" << endl;
     return -1;
  }
cout << "Input and output files opened properly\n\n";

char line[100];
char date[11], name[30], team[20], opp[20], home_away, three[3], reb[3], ass[3], stl[3], pts[3];
int N = 0, i, j;

fgets(line, 99, input);
while (!feof(input)){
int i = 0, k = 0, j;

while ((date[i++] = line[k++]) != ',');
    date[i-1] = '\0';
i=0;
while ((name[i++] = line[k++])!= ',');
    for (j = i-1; j<29; j++)
        name[j] = ' ';
    name[j] ='\0';
i = 0;
while ((team[i++] = line[k++]) != ',');
    for (j = i-1; j<19; j++)
        team[j] = ' ';
    team[j] = '\0';
i = 0;
while ((opp[i++] = line[k++]) != ',');
    for (j = i-1; j<19; j++)
        opp[j] = ' ';
    opp[j] = '\0';
i = 0;
home_away = line[k++];k++;
while ((three[i++] = line[k++]) != ',');
    three[i-1] = '\0';
i = 0;
while ((reb[i++] = line[k++]) != ',');
    reb[i-1] = '\0';
i = 0;
while ((ass[i++] = line[k++]) != ',');
    ass[i-1] = '\0';
i = 0;
while ((stl[i++] = line[k++]) != ',');
    stl[i-1] = '\0';
i = 0;
while ((pts[i++] = line[k++]) != '\n');
    pts[i-1] = '\0';

printf("%4d %10s %30s %20s %20s %1c %3s %3s %3s %3s %3s\n", N, date, name, team, opp, home_away, three, reb, ass, stl, pts);
fprintf(output, "%4d %10s %30s %20s %20s %1c %3s %3s %3s %3s\n", N, date, name, team, opp, home_away, three, reb, ass, stl, pts);
N++;
fgets(line, 99, input);
}

cout << "\nData has been read and printed\n";
cout << "and database file created.\n";

fclose(input);
fclose(output);

return 0;
}
