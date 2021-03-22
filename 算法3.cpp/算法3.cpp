#include<iostream>
#define max 10000
using namespace std;
int t[max];
int x,n,answer;
void Sequentialsearch(int answer){//顺序查找
    int i;
    for(i=0 ;i<n; ++i){
        if(t[i]== answer){
            cout << i << endl;//找到x，输出下标；
            break;
        }
    }
    if(i==n){
        cout<< "j=0" << endl;
    }
}
void Binarysearch(int answer){//二分查找
    int left=0,right=n-1,middle;
    while(left<=right){
        middle = (left+right)/2 ;
        if (answer == t[middle]){
            cout << middle+1 <<endl;
            break;
        }
        else if(answer< t[middle]){
            right = middle - 1;
        }else{
            left = middle + 1;
        }
        if(left>right){
            cout<< "j=0"<<endl;
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    cin>>x;
    Sequentialsearch(x);
    Binarysearch(x);

    return 0;

}