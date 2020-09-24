#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,rta=0,aux=0;
    cin >> n;
    if(n==1)cout<<1<<endl;
    else{
		rta=0;aux=0;
		int total[n],left[n],right[n];
		for(int i=0;i<n;i++){
			cin >> total[i];
		}
		left[0]=0;
		for(int i=1;i<n;i++){
			if(total[i]>total[i-1]) left[i]=left[i-1]+1;
			else left[i]=0;
			if(rta<left[i]) rta=left[i];
		}
		right[n-1]=0;
		for(int i=n-2;i>=0;i--){
			if(total[i]<total[i+1])right[i]=right[i+1]+1;
			else right[i]=0; 
			rta = max(rta, right[i]); 
		}
		rta++;
		for(int i=1;i<n-1;i++){
			if(left[i]==0){
				if(total[i+1]-total[i-1]>1)
					aux=(2+left[i-1]+right[i]);
				if(aux>rta) rta=aux;
			}
		}
		if(left[n-1]==0) aux=left[n-2]+1;
		if(aux>rta) rta=aux;
		cout << rta << endl;
	}
}