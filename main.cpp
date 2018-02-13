#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    FILE *input;
    FILE *output;
    input = fopen("csv_data.csv", "r");

    if (input == nullptr)
    {
        cout << "Could not open file" << endl;
        return -1;
    }

    output = fopen("formatted_data.txt", "w");

    if (output == nullptr)
    {
        cout << "Could not create output file" << endl;
        return -1;
    }

    cout << "Input and output files opened properly\n\n";

    char line[100], out_line[100];
    char ind[6], cname[30], grp[4], mrk[10];

    fgets(line, 99, input);

    while (!feof(input))
    {
        int i = 0, k = 0, j;
        while ((ind[i++] = line[k++]) != ';');
        ind[i-1] = '\0';
        i=0;
        
        while ((cname[i++] = line[k++])!= ';');
        for (j = i-1; j<29; j++)
            cname[j] = ' ';
        cname[29] ='\0';
        i = 0;
        
        while ((grp[i++] = line[k++]) != ';');
        grp[i-1] = '\0';
        i = 0;
        
        while ((mrk[i++] = line[k++]) != '\0');
        mrk[i-1] = '\0';

        int index, groupId;
        char name[30];
        char name2[30];
        float score;

        sscanf(ind, "%d", &index);
        sscanf(cname, "%s %s", name, name2);
        strcat(name, " ");
        strcat(name, name2);
        sscanf(grp, "%d", &groupId);
        sscanf(mrk, "%f", &score);

        sprintf(out_line, "%5d %30s %3d %5.2f\n", index, name, groupId, score);
        fputs(out_line, output);
        printf("%s", out_line);
        fgets(line, 99, input); //next iteration
    }

    cout << "\nData has been read and printed\n";
    cout << "and txt database file created.\n";

    fclose(input);
    fclose(output);

    return 0
}
