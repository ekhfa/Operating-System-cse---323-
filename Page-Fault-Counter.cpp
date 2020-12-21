#include<bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];
int mark[N]; //default zero && zero means false

void lru_page_replacement()
{
    unordered_set<int> Q;
    unordered_map<int, int> indexes;

    int page_faults = 0;
    for (int i=0; i<n; i++)
    {

        if(Q.find(pages[i])!=Q.end())
        {
            cout<<"No page fault for: "<<pages[i]<<"\n";
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
            cout<<"page fault for: "<<pages[i]<<"\n";

        }
        indexes[pages[i]] = i;
    }

    cout<<"\nTotal Page Faults: "<<page_faults;
}

void fifo_page_replacement(void)
{
    queue<int> Q;
    int page_faults=0;

    for(int i=0; i<n; i++)
    {
        if(mark[pages[i]]==true)
        {
            cout<<"No page fault for: "<<pages[i]<<"\n";
        }
        else
        {
            Q.push(pages[i]);
            mark[pages[i]]=true;
            if(Q.size()>frame_size)
            {
                int p= Q.front();
                mark[p]=false;
                Q.pop();
            }
            page_faults++;
            cout<<"page fault for: "<<pages[i]<<"\n";
        }

    }
    cout<<"\nTotal Page Faults: "<<page_faults;
    return;
}

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


int main()
{
    freopen("input.txt", "r", stdin);

    cout<<"Number of Frames: ";
    cin>>frame_size;

    cout<<"Page Reference Stream Length: ";
    cin>>n;

    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
        cin>>pages[i];

    lru_page_replacement();
    cout<<"\n";

    fifo_page_replacement();
    cout<<"\n";

    optimal_page_replacement();

    return 0;
}
