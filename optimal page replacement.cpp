#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];
int mark[N]; //default zero && zero means false
void optimal_page_replacement()
{
    vector<int> fr;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        for (k = 0; k < fr.size(); k++)
            if (fr[k] == pages[i])
                break;
        if (k==fr.size())
        {
            if (fr.size() < frame_size)
                fr.push_back(pages[i]);

            else
            {
                int index=i+1;
                int res = -1, farthest = index;
                for (int l = 0; l < fr.size(); l++)
                {
                    int j;
                    for (j = index; j < n; j++)
                    {
                        if (fr[l] == pages[j])
                        {
                            if (j > farthest)
                            {
                                farthest = j;
                                res = l;
                            }
                            break;
                        }
                    }
                    if (j == n)
                    {
                        res=l;
                        break;
                    }
                }
                fr[res] = pages[i];
            }
            page_faults++;
            cout<<"page fault for: "<<pages[i]<<"\n";
        }
        else
        {
            cout<<"No page fault for: "<<pages[i]<<"\n";
        }
    }
    cout<<"\nTotal Page Faults: "<<page_faults;
}