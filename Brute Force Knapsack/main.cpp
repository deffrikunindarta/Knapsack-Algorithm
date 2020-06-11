   #include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


void generates(int k, vector<bool> & my_set, int N, int item[], float profit[],float weight[],float sizes[],float capacity,float volume, float &maxprofit){
//generating subsets from array of item
//shows it's total profit and total weight
//looking for the biggest profit
    float totalprofit=0;
    float totalweight=0;
    float totalsize=0;
	if(k == N){
		// shows the subset
		cout << "   { ";
		int i = 0;
		while( i < N ){
			if(my_set[i] == true){
				cout << i + 1 << " ";
				totalprofit=totalprofit+profit[i];
                totalweight=totalweight+weight[i];
                totalsize = totalsize+sizes[i];

			}
			i++;
		}
        cout << "}";

        if(totalweight>capacity || totalsize>volume){
            cout<<"                 profit : "<<totalprofit<<"              weight : "<<totalweight<<"                 volume : " <<totalsize<<"   not feasible "<<endl;
        }else {

            cout<<"                 profit : "<<totalprofit<<"              weight : "<<totalweight<<"                 volume : " <<totalsize<<endl;
            if(totalprofit>=maxprofit){
                maxprofit=totalprofit;
            }
        }
        totalprofit=0;
        totalweight=0;

	}
	else
	{
		my_set[k] = true;
		generates(k + 1, my_set, N, item ,profit,weight,sizes,capacity,volume, maxprofit);
		my_set[k] = false; // backtracking
		generates(k + 1, my_set, N , item , profit,weight,sizes,capacity,volume,maxprofit);
	}
}
void insertWeight(float weight[],int N){
//insert weight from the input into the array of weight
    int i=0;
    float w;
    while (i<N){
        cout<<"   insert weight of item number "<<i+1<<" : ";
        cin>>w;
        weight[i]=w;
        i++;
    }


}

void insertSize(float sizes[],int N){
//insert weight from the input into the array of weight
    int i=0;
    float s;
    while (i<N){
        cout<<"   insert size of item number "<<i+1<<" : ";
        cin>>s;
        sizes[i]=s;
        i++;
    }


}


void insertProfit(float profit[], int N){
//insert profit from the input into array of profit
    int i=0;
    float p;
    while (i < N){
        cout<<"   insert profit of item number "<<i+1<<" : ";
        cin>>p;
        profit[i]=p;
        i++;
    }

}

void getItem ( int item[],int N){
//insert item number from input into the array of item
    int i =1;
    int j= 0;
    while(i<= N){
        item[j]=i;
        i++;
        j++;
    }

}

void print ( int item[], float profit[], float weight[], int N){
//print all of items and it's profits and weights
    int i=0;
    cout<<"   item no : ";
	while(i<N){
        cout<<item[i]<<",";
        i++;
	}
	cout<<endl;
	int j=0;
	cout<<"   profit : ";
    while(j<N){
        cout<<profit[j]<<",";
        j++;
	}
	cout<<endl;
	int k=0;
	cout<<"   weight : ";
    while(k<N){
        cout<<weight[k]<<",";
        k++;
	}
}

int main(int argc, char *argv[]){
	int N;
	float capacity,volume;
    cout << endl << "   ---------------------------------------" << endl;
    cout << endl << "         Knapsack Brute Force Algorithm   " << endl;
    cout << endl << "   ---------------------------------------" << endl;
	cout<<"   insert number of item : ";
	cin >> N;
	cout<<"   insert Capacity : ";
	cin >> capacity;
    cout<<"   insert Size : ";
	cin >> volume;
    float maxprofit;
	float profit[N];
	float weight[N];
	float sizes[N];
	int item[N];
	getItem(item,N);
	insertProfit(profit,N);
	insertWeight(weight,N);
	insertSize(sizes, N);
	vector<bool> my_set(N);
	cout<<endl;
	cout<<endl;
    print(item,profit,weight,N);
    cout<<endl;
    cout<<endl;
    auto start = high_resolution_clock::now();
	generates(0, my_set, N, item, profit,weight,sizes,capacity,volume,maxprofit);
	auto stop = high_resolution_clock::now();
    cout<<endl;
    cout<<endl;
    cout<<"   Profit of Optimal Solution : "<<maxprofit<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"   Time taken by function: "<< duration.count()*0.000001<< " s" << endl;
	return 0;
}
