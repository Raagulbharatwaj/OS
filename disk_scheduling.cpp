#include<iostream>
#include<vector>
using namespace std;

void fcfs(vector<int>,int,int);
void sstf(vector<int>,int,int);
void scan(vector<int>,int,int);
void look(vector<int>,int,int);
void cscan(vector<int>,int,int);

int main()
{
    int len;
    cout<<"Enter the number of pending requests:"<<endl;
    cin>>len;
    vector<int> waiting_queue;
    cout<<"Enter the disk locations in order of waiting:"<<endl;
    for(int i=0;i<len;i++)
    {
        int x;
        cin>>x;
        waiting_queue.push_back(x);
    }
    int curr_pos;
    cout<<"Enter the current postion of the reader in the disk:"<<endl;
    cin>>curr_pos;
    fcfs(waiting_queue,len,curr_pos);
    sstf(waiting_queue,len,curr_pos);
    scan(waiting_queue,len,curr_pos);
    look(waiting_queue,len,curr_pos);
    cscan(waiting_queue,len,curr_pos);
    return 0;
}
int find_sst(int start,int end,int* arr,int p)
{
    int min = abs(arr[start]-p);
    int min_index = start;
    for(int i = start;i<end;i++)
    {
        if(abs(arr[i]-p)<min)
        {
            min = abs(arr[i]-p);
            min_index = i;
        }
    }
    return min_index;
}
void  sstf_sort(int* arr, int n,int p)
{
    int head = p;
    for(int i=0;i<n;i++)
    {
        int index  = find_sst(i,n,arr,head);
        int temp   = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
        head = arr[i];
    }
}
int find_directional_min(int start,int end,int* arr,int p)
{
    int min = arr[start];
    int min_index = start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]>=p && arr[i]<min)
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}
int find_directional_max(int start,int end,int* arr,int p)
{
    int max = arr[start];
    int max_index = start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<p && arr[i]>max)
        {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}
void left_right_sort(int* arr,int n,int head)
{
    int min_count = 0;
    int max_count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<head)
        {
            min_count++;
        }
        else 
        {
            max_count++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(max_count>0)
        {
            int index = find_directional_min(i,n,arr,head);
            int temp   = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            head = arr[i];
            max_count--;
        }
        else 
        {
            int index = find_directional_max(i,n,arr,head);
            int temp   = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
            head = arr[i];
        }
    }
}
void fcfs(vector<int> arr,int n,int p)
{
    int distance = 0;
    int curr_pos = p;
    for(int i=0;i<n;i++)
    {
        int dist_travelled = abs(arr[i]-curr_pos);
        curr_pos = arr[i];
        distance+= dist_travelled;
    }
    cout<<"-----------------FCFS-----------------"<<endl;
    cout<<"DISTANCE TRAVELLED:"<<distance<<endl;
    cout<<"--------------------------------------"<<endl;
}
void sstf(vector<int> arr,int n,int p)
{
    int* requests = new int[n];
    for(int i=0;i<n;i++)
    {
        requests[i] = arr[i];
    }
    sstf_sort(requests,n,p);
    int distance = 0;
    int curr_pos = p;
    for(int i=0;i<n;i++)
    {
        int dist_travelled = abs(requests[i]-curr_pos);
        curr_pos = requests[i];
        distance+= dist_travelled;
    }
    cout<<"-----------------SSTF-----------------"<<endl;
    cout<<"DISTANCE TRAVELLED:"<<distance<<endl;
    cout<<"--------------------------------------"<<endl;
    delete [] requests;
}

void scan(vector<int> arr,int n,int p)
{
    int* requests = new int[n];
    for(int i=0;i<n;i++)
    {
        requests[i] = arr[i];
    }
    left_right_sort(requests,n,p);
    int distance = 0;
    int curr_pos = p;
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<p && flag==0)
        {
            int temp = abs(3000-curr_pos);
            distance+= temp;
            flag = 1;
            curr_pos = 2999;
            continue;
        }
        int dist_travelled = abs(requests[i]-curr_pos);
        curr_pos = requests[i];
        distance+= dist_travelled;
    }
    distance+= curr_pos;
    cout<<"-----------------SCAN-----------------"<<endl;
    cout<<"DISTANCE TRAVELLED:"<<abs(p-3000)+3000<<endl;
    cout<<"--------------------------------------"<<endl;
}
void look(vector<int> arr,int n,int p)
{
    int* requests = new int[n];
    for(int i=0;i<n;i++)
    {
        requests[i] = arr[i];
    }
    left_right_sort(requests,n,p);
    int distance = 0;
    int curr_pos = p;
    for(int i=0;i<n;i++)
    {
        int dist_travelled = abs(requests[i]-curr_pos);
        curr_pos = requests[i];
        distance+= dist_travelled;
    }
    cout<<"-----------------LOOK-----------------"<<endl;
    cout<<"DISTANCE TRAVELLED:"<<distance<<endl;
    cout<<"--------------------------------------"<<endl;
    delete [] requests;
}
void cscan(vector<int> arr,int n,int p)
{
    int* requests = new int[n];
    for(int i=0;i<n;i++)
    {
        requests[i] = arr[i];
    }
    left_right_sort(requests,n,p);
    int distance = 0;
    int curr_pos = p;
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<p && flag==0)
        {
            distance+= 3000-curr_pos;
            flag = 1;
            curr_pos = 0;
            continue;
        }
        int dist_travelled = abs(requests[i]-curr_pos);
        curr_pos = requests[i];
        distance+= dist_travelled;
    }
    cout<<"-----------------CSCAN-----------------"<<endl;
    cout<<"DISTANCE TRAVELLED:"<<distance<<endl;
    cout<<"--------------------------------------"<<endl;
    delete [] requests;   
}