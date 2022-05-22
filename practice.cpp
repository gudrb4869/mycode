#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> s={2,3,6,9};
set<int>::iterator it;

int main(){
    cout << *s.lower_bound(10) << '\n';
}
/*
#include <iostream>
#include <string>
#include <stdlib.h>
 
using namespace std;
 
 
int main(void)
{
    
    int *team_id;
    string team[] = { "Heros", "Eagles", "Dinos", "Lions", "Wiz",
                    "Twins", "Wyverns" ,"Tigers","Bears","Giants"};
    int numTeam = sizeof(team)/sizeof(string);
    team_id = (int*)malloc(numTeam*sizeof(int));
 
    for (int i = 0; i < numTeam; i++) {
        team_id[i] = i;
    }
 
    for (int i = 0; i < numTeam - 1; i++) {
        cout << i + 1 << "ÀÏÂ÷" << endl;
        for (int j = 0; j < numTeam/2; j++) {
            cout << team[team_id[j]] << ":" << team[team_id[numTeam-j-1]] << endl;
        }
 
        for (int j = 0; j < numTeam - 1; j++) {
            team_id[j] = (team_id[j] + 1) % (numTeam - 1);
        }
 
        cout << endl;
    }
    
    return 0;
}
*/