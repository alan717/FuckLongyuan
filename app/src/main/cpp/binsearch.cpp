#include <iostream>

using namespace std;

int Binary_search(const int vector[],int value){

    int low=0;
    int high=sizeof(vector)/sizeof(vector[0])-1;
    cout<<"vec:"<< sizeof(vector)<<endl;

    cout<<";vector[0]:"<<sizeof(vector[0])<<endl;
    cout<<"high:"<<high<<endl;

    int middle;
    while(low<=high){
        middle=(low+high)/2;
        if(vector[middle]>value){
            high=middle-1;
        }
        if(vector[middle]<value){
            low=middle+1;
        }
        if(vector[middle]==value){
            return middle;
        }
    }
}


int main(){
    const int a[]={1,2,5,8,19,25,30,40,47,48,69,30,90};
}