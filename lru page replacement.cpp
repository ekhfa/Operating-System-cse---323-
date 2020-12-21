#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];
int mark[N];

void lru_page_replacement()
{
    unordered_set<int> Q;
    unordered_map<int, int> indexes;

    int page_faults = 0;
    for (int i=0; i<n; i++)
    {

        if(Q.find(pages[i])!=Q.end())
        {
            cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
        else
        {
            if (Q.size() < frame_size)
            {
                Q.insert(pages[i]);
                page_faults++;
            }
            else
            {
                int lru = INT_MAX, val;
                for (auto it : Q)
                {
                    if (indexes[it] < lru)
                    {
                        lru = indexes[it];
                        val = it;
                    }
                }
                Q.erase(val);
                Q.insert(pages[i]);
                page_faults++;
            }
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";

        }
        indexes[pages[i]] = i;
    }

    cout<<"\nTotal Page Faults: "<<page_faults;
}



