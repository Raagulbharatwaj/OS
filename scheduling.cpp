#include<iostream>
using namespace std;
void sort(int arr[][3],int n,int mode)
{
int i,j,temp=0;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(arr[j][mode]<arr[i][mode])
{
temp=arr[j][0];
arr[j][0]=arr[i][0];
arr[i][0]=temp;
temp=arr[j][1];
arr[j][1]=arr[i][1];
arr[i][1]=temp;
temp=arr[j][2];
arr[j][2]=arr[i][2];
arr[i][2]=temp;
}
}
}
}
float FirstComeFirstServe(int arr[][3],int n)
{
sort(arr,n,0);
int wt[n]={ 0 };
float avg_wait=0;
int tat[n]={ 0 };
float avg_tat=0;
for (int i = 1; i < n ; i++ )
{
wt[i] = arr[i-1][1] + wt[i-1];
avg_wait+=wt[i];
}
for (int i = 0; i < n ; i++)
{
tat[i] = arr[i][1] + wt[i];
avg_tat+=tat[i];
}
avg_wait/=n;
avg_tat/=n;
cout<<"Average Waiting time for First Come First Serve = "<<avg_wait<<" ms";
cout<<"\nAverage Turn Around time for First Come First Serve = "<<avg_tat<<" ms\n";
return avg_wait;
}
float ShortestJobFirst(int arr[][3],int n)
{
sort(arr,n,1);
int wt[n]={0};
float avg_wait=0;
int tat[n]={0};
float avg_tat=0;
for (int i = 1; i < n ; i++ )
{
wt[i] = arr[i-1][1] + wt[i-1];
avg_wait+=wt[i];
}
for (int i = 0; i < n ; i++)
{
tat[i] = arr[i][1] + wt[i];
avg_tat+=tat[i];
}
avg_wait/=n;
avg_tat/=n;
cout<<"Average Waiting time for Shortest Job First = 
"<<avg_wait<<" ms";
cout<<"\nAverage Turn Around time for Shortest Job First 
= "<<avg_tat<<" ms\n";
return avg_wait;
}
float NonPreemptivePriority(int arr[][3],int n)
{
sort(arr,n,2);
int wt[n]={0};
float avg_wait=0;
int tat[n]={0};
float avg_tat=0;
for (int i = 1; i < n ; i++ )
{
wt[i] = arr[i-1][1] + wt[i-1];
avg_wait+=wt[i];
}
for (int i = 0; i < n ; i++)
{
tat[i] = arr[i][1] + wt[i];
avg_tat+=tat[i];
}
avg_wait/=n;
avg_tat/=n;
cout<<"Average Waiting time for Non Preemptive Priority 
Scheduling = "<<avg_wait<<" ms";
cout<<"\nAverage Turn Around time for Non Preemptive 
Priority Scheduling = "<<avg_tat<<" ms\n";
return avg_wait;
}
float RoundRobin(int arr[][3],int n,int qt)
{
sort(arr,n,0);
bool flag=1;
int t=0;
int wt=0,tat=0;
int bt[n];
for(int i=0;i<n;i++)
bt[i]=arr[i][1];
while(flag)
{
flag=0;
for(int i=0;i<n;i++)
{
if(arr[i][0]>t)
{
flag=1;
continue;
}
if(bt[i]>0)
{
flag=1;
if(bt[i]>qt)
{
t+=qt;
bt[i]-=qt;
}
else
{
t+=bt[i];
wt+=((t-arr[i][1])-arr[i][0]);
tat+=(t-arr[i][0]);
bt[i]=0;
}
}
}
}
float avg_wait=wt/n;
float avg_tat=tat/n;
cout<<"Average Waiting time for Round Robin = 
"<<avg_wait<<" ms";
cout<<"\nAverage Turn Around time for Round Robin = 
"<<avg_tat<<" ms\n";
return avg_wait;
}
float ShortestJobRemainingFirst(int arr[][3],int n)
{
bool flag=0;
int wt=0,tat=0,min=0,minm=INT_MAX,t=0,complete=0,temp=0;
int bt[n]={0};
for(int i=0;i<n;i++)
bt[i]=arr[i][1];
while(complete!=n)
{
for(int i=0;i<n;i++)
{
if(bt[i]<minm && arr[i][0]<=t && bt[i]>0)
{
min=i;
minm=bt[i];
flag=1;
}
}
if(flag==0)
{
t++;
continue;
}
bt[min]--;
minm=bt[min];
if(bt[min]==0)
{
minm=INT_MAX;
complete++;
flag=0;
temp=((t+1)-arr[min][1])-arr[min][0];
if(temp<0)temp=0;
wt+=temp;
tat+=arr[min][1]+temp;
}
t++;
}
float avg_wait=wt/n;
float avg_tat=tat/n;
cout<<"Average Waiting time for Shortest Job Remaining 
First = "<<avg_wait<<" ms";
cout<<"\nAverage Turn Around time for Shortest Job 
Remaining First = "<<avg_tat<<" ms\n";
return avg_wait;
}
float PreemptivePriorityScheduling(int arr[][3],int n)
{
bool flag=0;
int wt=0,tat=0,min=0,t=0,complete=0,temp=0;
int bt[n]={0},pt[n]={0};
for(int i=0;i<n;i++)
bt[i]=arr[i][1];
for(int i=0;i<n;i++)
pt[i]=arr[i][2];
while(complete!=n)
{
for(int i=0;i<n;i++)
{
if(pt[i]<pt[min] && arr[i][0]<=t && bt[i]>0)
{
min=i;
flag=1;
}
}
if(flag==0)
{
t++;
continue;
}
bt[min]--;
if(bt[min]==0)
{
complete++;
flag=0;
temp=((t+1)-arr[min][1])-arr[min][0];
if(temp<0)temp=0;
wt+=temp;
tat+=arr[min][1]+temp;
pt[min]=INT_MAX;
}
t++;
}
float avg_wait=wt/n;
float avg_tat=tat/n;
cout<<"Average Waiting time for Preemptive Priority 
Scheduling = "<<avg_wait<<" ms";
cout<<"\nAverage Turn Around time for Preemptive Priority 
Scheduling = "<<avg_tat<<" ms\n";
return avg_wait;
}
int main()
{
int j,qt=0;
cout<<"Enter number of processes\n";
cin>>j;
int arr[j][3];
cout<<"Enter arrival time, burst time and priority of 
each process\n";
for(int i=0;i<j;i++)
{
cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
}
cout<<"Enter time quantum if applicable: ";
cin>>qt;
float wt[6]={0};
wt[0] = FirstComeFirstServe(arr,j);
wt[1] = ShortestJobFirst(arr,j);
wt[2] = NonPreemptivePriority(arr,j);
wt[5] = RoundRobin(arr,j,qt);
wt[4] = ShortestJobRemainingFirst(arr,j);
wt[3] = PreemptivePriorityScheduling(arr,j);
float temp=0;
float temp1[6]={0};
for(int i=0;i<6;i++)
{
temp1[i]=wt[i];
}
for(int i=0;i<j;i++)
{
for(int k=i+1;k<j;k++)
{
if(temp1[k]<temp1[i])
{
temp=temp1[k];
temp1[k]=temp1[i];
temp1[i]=temp;
}
}
}
int ans;
for(int i=0;i<6;i++)
{
if(temp1[0]==wt[i])
{
ans=i;
break;
}
}
switch(ans)
{
case 0:
cout<<"First Come First Serve has the least waiting time 
= ";
break;
case 1:
cout<<"Shortest Job First has the least waiting time = ";
break;
case 2:
cout<<"Non Preemptive Priority Scheduling has the least 
waiting time = ";
break;
case 3:
cout<<"Preemptive Priority Scheduling has the least 
waiting time = ";
break;
case 4:
cout<<"Shortest Job Remaining First has the least waiting 
time = ";
break;
case 5:
cout<<"Round Robin has the least waiting time = ";
break;
default:
break;
}
cout<<temp1[0]<<" ms\n";
return 0;
}
