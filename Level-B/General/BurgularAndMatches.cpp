using namespace std;
#include<vector>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<algorithm>



vector<int>mtch;
vector<int>mtchbox;
int n,m=0; // n max number of matchboxes, m number of containers
// get container index that has matchboxes with maximum numbers of matches
int contIndex(){
    int max=-1;
    int index=-1;
    for(int i=0;i<m;i++){
        if(mtch[i]>max){
            index=i;
            max=mtch[i];
        }
    }
    return index;
}

int main(){
    cin>>n>>m;
    int temp=0;
    for(int i=0;i<m;i++){
        cin>>temp;
        mtchbox.push_back(temp);
        cin>>temp;
        mtch.push_back(temp);
    }
    int ans=0;
    int remCont=n;
    while(remCont>0){
        int maxIdx=contIndex();
        if(maxIdx==-1)
            break;
        ans+=std::max(mtchbox[maxIdx],remCont)*mtch[maxIdx];
        remCont-=std::max(mtchbox[maxIdx],remCont);
        mtch[maxIdx]=-1;
    }
    cout<<ans;
    return 0;

}