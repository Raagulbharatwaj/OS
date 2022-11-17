#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct frames
{
    int n;
    int *pages;
}frames;
frames* create_frames(int n)
{
    frames* f = (frames*)malloc(sizeof(frames));
    f->n = n;
    f->pages  = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        f->pages[i] = -1;
    }
    return f;
}
void print_frames(frames* f)
{
    cout<<"Frame Contents"<<endl;
    for(int i=0;i<f->n;i++)
    {
        cout<<f->pages[i]<<" ";
    }
    cout<<endl;
}
int search(int p_no,frames* f)
{
    for(int i=0;i<f->n;i++)
    {
        if(f->pages[i]==p_no)
        {
            return 1;
        }
    }
    return 0;
}
void replace(int p_no,frames* f)
{
    for(int i=0;i<(f->n)-1;i++)
    {
        f->pages[i] = f->pages[i+1];
    }
    f->pages[(f->n)-1] = p_no;
    cout<<"Page replaced successfully"<<endl;
    print_frames(f);
}
int is_full(frames* f)
{
    for(int i=0;i<f->n;i++)
    {
        if(f->pages[i]==-1)
        {
            return 0;
        }
    }
    return 1;
}
void append(frames* f,int x)
{
    for(int i=0;i<f->n;i++)
    {
        if(f->pages[i]==-1)
        {
            f->pages[i] = x;
            break;
        }
    }
    print_frames(f);
}
void replace_frame(frames* f,int p_no,int lru_frame)
{
    for(int i=0;i<f->pages[i];i++)
    {
        if(f->pages[i]==lru_frame)
        {
            f->pages[i] = p_no;
            break;
        }
    }
    print_frames(f);
}
void fifo_replacement(frames* f,int* page_seq,int m)
{
    int hits   = 0;
    int faults = 0;
    for(int i=0;i<m;i++)
    {
        if(search(page_seq[i],f))
        {
            printf("page hit\n");
            hits++;
        }
        else
        {
            faults++;
            if(is_full(f))
            {
                replace(page_seq[i],f);
            }
            else
            {
                append(f,page_seq[i]);
            }
        }
    }
    cout<<"\n ----- SUMMARY OF RUN ----- ";
    cout<<"\nAlgorithm : FIFO";
    cout<<"\nNumber of page Faults :"<<faults;
    cout<<"\nNumber of page Hits : "<<hits;
    cout<<"\nHit rate: "<<((double)hits/m)*100<<" %";
    cout<<"\n -------------------------- ";
}
void lru_replacement(frames* f,int* page_seq,int m)
{
    int hits   = 0;
    int faults = 0;
    for(int i=0;i<m;i++)
    {
        if(search(page_seq[i],f))
        {
            printf("page hit\n");
            hits++;
        }
        else
        {
            faults++;
            int lru_frame;
            int found[f->n];
            for(int k=0;k<f->n;k++)
            {
                found[k] = -1;
            }
            int index = 0;
            if(is_full(f))
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(search(page_seq[j], f))
                    {
                        if(index == (f->n)-1)
                        {
                            break;
                        }
                        found[index] = page_seq[j]; 
                    }
                }
                for(int k = 0;k<f->n;k++)
                {
                    if(found[k]==-1)
                    {
                        break;
                    }
                    lru_frame = found[k];
                }
                replace_frame(f,page_seq[i],lru_frame);
            }
            else
            {
                append(f,page_seq[i]);
            }
        }
    }
    cout<<"\n ----- SUMMARY OF RUN ----- ";
    cout<<"\nAlgorithm : Least Recently Used";
    cout<<"\nNumber of page Faults : "<<faults;
    cout<<"\nNumber of page Hits : "<<hits;
    cout<<"\nHit rate: "<<((double)hits/m)*100<<" %";
    cout<<"\n -------------------------- ";
}
void optimal_replacement(frames* f,int* page_seq,int m)
{
    int hits   = 0;
    int faults = 0;
    for(int i=0;i<m;i++)
    {
        if(search(page_seq[i],f))
        {
            printf("page hit\n");
            hits++;
        }
        else
        {
            faults++;
            int lru_frame = -1;
            int found[f->n];
            for(int k=0;k<f->n;k++)
            {
                found[k] = -1;
            }
            int index = 0;
            if(is_full(f))
            {
                for(int j=i+1;j<m;j++)
                {
                    if(search(page_seq[j], f))
                    {
                        if(index == (f->n)-1)
                        {
                            break;
                        }
                        found[index] = page_seq[j]; 
                    }
                    else
                    {
                        lru_frame = page_seq[j];
                        break;
                    }
                }
                if(lru_frame==-1)
                {
                    for(int k = 0;k<f->n;k++)
                    {
                        if(found[k]==-1)
                        {
                            break;
                        }
                        lru_frame = found[k];
                    }
                }
                replace_frame(f,page_seq[i],lru_frame);
            }
            else
            {
                append(f,page_seq[i]);
            }
        }
    }
    cout<<"\n ----- SUMMARY OF RUN ----- ";
    cout<<"\nAlgorithm : Optimal Replacement";
    cout<<"\nNumber of page Faults : "<<faults;
    cout<<"\nNumber of page Hits : "<<hits;
    cout<<"\nHit rate: %f percent"<<((double)hits/m)*100;
    cout<<"\n -------------------------- ";
}
int main()
{
    int n;
    int m;
    cout<<"\nEnter the length of page sequence\n";
    cin>>m;
    cout<<"\nEnter the page sequence\n";
    int* page_sequence = (int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        page_sequence[i] = x;
    }
    cout<<"\nEnter the length of frame\n";
    cin>>n;
    frames* f = create_frames(n);
    cout<<"\n---------- MENU ----------";
    cout<<"\n1. FIFO \n2. LRU \n3. OPTIMAL\n";
    int choice;
    cin>>choice;
    cout<<choice<<endl;
    switch(choice)
    {
        case 1:
            fifo_replacement(f, page_sequence,m);
            break;
        case 2:
           lru_replacement(f, page_sequence,m);
           break; 
        case 3:
            optimal_replacement(f, page_sequence,m);
            break;
    }
    free(f);
    free(page_sequence);
}