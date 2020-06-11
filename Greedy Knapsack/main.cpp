#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void greedyBySize(float profit[], float sizes[], int N, int volume){

    float x = 0;
    float w = 0;
    float p = 0;
    float minweight = 0;
    int i = 0;
    int j = 0;
    int para = 0;
    cout << "   Greedy By Volume" << endl;
    //cout << "   Subset = {";
    while (para < volume){
        i = 0;
        j = 0;
        minweight = sizes[i];
        while (i < N){
            if (minweight > sizes[i]){
                minweight = sizes[i];
                j = i;
            }
            i++;
        }
        w = w + minweight;
        para = w;
        if (w > volume){
            w = w - minweight;
        }else{
            p = p + profit[j];
            while (j < N){
                sizes[j]=sizes[j+1];
                profit[j]=profit[j+1];
                j++;
            }
            sizes[j]=0;
            profit[j]=0;
            N = N -1;
        }
        if(j!=0){
           // cout<<j<<",";
        }else{
            para = volume;
        }
    }
    //cout<<"}"<<endl;
    //cout << "capacity = "<< capacity <<endl;
    cout << "   total profit = "<<p <<endl;
    cout << "   total volume = "<<w <<endl;
    cout << endl;

}

void greedyByWeight(float profit[], float weight[], int N, int capacity){
    float x = 0;
    float w = 0;
    float p = 0;
    float minweight = 0;
    int i = 0;
    int j = 0;
    int para = 0;
    cout << "   Greedy By Weight" << endl;
    //cout << "   Subset = {";
    while (para < capacity){
        i = 0;
        j = 0;
        minweight = weight[i]
        ;
        while (i < N){
            if (minweight > weight[i]){
                minweight = weight[i];
                j = i;
            }
            i++;
        }
        w = w + minweight;
        para = w;
        if (w > capacity){
            w = w - minweight;
        }else{
            p = p + profit[j];
            while (j < N){
                weight[j]=weight[j+1];
                profit[j]=profit[j+1];
                j++;
            }
            weight[j]=0;
            profit[j]=0;
            N = N -1;
        }
        if(i!=0){
            //cout<<i<<",";
        }else{
            para = capacity;
        }
    }
    //cout<<"}"<<endl;
    //cout << "   GREEDY BY WEIGHT" << endl;
    //cout << "capacity = "<< capacity <<endl;
    cout << "   total profit = "<<p <<endl;
    cout << "   total weight = "<<w <<endl;
    cout << endl;

}

void greedyByProfit(float profit[], float weight[], int N, int capacity){

    float x = 0;
    float w = 0;
    float p = 0;
    float maxprofit = 0;
    int i = 0;
    int j = 0;
    int para = 0;
    cout << "   Greedy By Profit" <<endl;
    //cout << "   Subset = {";
    while (para < capacity){
        i = 0;
        j = 0;
        maxprofit = 0;
        while (i < N){
            if (maxprofit < profit[i]){
                maxprofit = profit[i];
                j = i;
            }
            i++;
        }
        w = w + weight[j];
        para = w;
        if (w > capacity){
            w = w - weight[j];
        }else{
            p = p + profit[j];
            while (j < N){
                weight[j]=weight[j+1];
                profit[j]=profit[j+1];
                j++;
            }
            weight[j]=0;
            profit[j]=0;
            N = N -1;
        }
        if(j!=0){
            //cout<<j<<",";
        }else{
            para = capacity;
        }
    }
    //cout<<"}"<<endl;
   // cout << "capacity = "<< capacity <<endl;
    cout << "   total profit = "<<p <<endl;
    cout << "   total weight = "<<w <<endl;

}

void greedyByDensity(float profit[], float weight[], float density[], int N, int capacity){

    float x = 0;
    float w = 0;
    float p = 0;
    float maxdensity = 0;
    int i = 0;
    int j = 0;
    int para = 0;
    cout << "   Greedy By Density" <<endl;
   // cout <<"   Subset = {";
    while (para < capacity){
        i = 0;
        j = 0;
        maxdensity = 0;
        ;
        while (i < N){
            if (maxdensity < density[i]){
                maxdensity = density[i];
                j = i;
            }

            i++;
        }
        w = w + weight[j];

        para = w;
        if (w > capacity){
            w = w - weight[j];
        }else{
            p = p + profit[j];
            while (j < N){
                weight[j]=weight[j+1];
                profit[j]=profit[j+1];
                j++;
            }
            weight[j]=0;
            profit[j]=0;
            N = N -1;
        }
        if(j!=0){
          //  cout<<j<<",";
        }else{
            para = capacity;
        }
    }
    //cout<<"}"<<endl;
   // cout << "capacity = "<< capacity <<endl;
    cout << "   total profit = "<<p <<endl;
   cout << "   total weight = "<<w <<endl;

}

void insertSize(float sizes[],int N){
//insert weight from the input into the array of weight
    int i=0;
    float s;
    while (i<N){
        cout<<"  insert volume of item number "<<i+1<<" : ";
        cin>>s;
        sizes[i]=s;
        i++;
    }


}

void insertWeight(float weight[],int N){
    int i=0;
    float w;
    while (i<N){
        cout<<"  insert weight of item number "<<i+1<<":";
        cin>>w;
        weight[i]=w;
        i++;
    }


}

void insertProfit(float profit[], int N){
    int i=0;
    float p;
    while (i < N){
        cout<<"  insert profit of item number "<<i+1<<":";
        cin>>p;
        profit[i]=p;
        i++;
    }

}

void getdensity(float profit[], float weight[], int N, float density[]){
    int i = 0;
    while (i < N){
        density[i] = profit[i] / weight[i];
        i++;
    }
}

int main() {
 int N;
 int capacity;
 int opt;
 int volume;
 cout << endl << "  ---------------------------------------" << endl;
 cout << endl << "          Knapsack Greedy Algorithm   " << endl;
 cout << endl << "  ---------------------------------------" << endl;
 cout << "  insert number of item : ";
 cin >> N;
 cout<<  "  insert capacity : ";
 cin>> capacity;
 cout<<  "  insert size : ";
 cin>> volume;
 float profit[N];
 float weight[N];
 float sizes[N];
 float density[N];
 insertProfit(profit,N);
 insertWeight(weight,N);
 insertSize(sizes,N);
 getdensity(profit,weight,N, density);
 cout << endl;
 cout << endl;
 cout << "  Choose Method : " <<endl;
 cout << "  1. Greedy By Weight" <<endl;
 cout << "  2. Greedy By Profit" <<endl;
 cout << "  3. Greedy By Density" <<endl;
 cout << "  4. Greedy By Volume" <<endl;
 cout << "  Choose Method number :";
 cin >> opt;
 cout << endl;
 if ( opt == 1){
    auto start = high_resolution_clock::now();
    greedyByWeight(profit,weight,N,capacity);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "   Time taken by function: "<< duration.count()*0.000001<< " s" << endl;
 }else if ( opt == 2){
    auto start = high_resolution_clock::now();
    greedyByProfit(profit,weight,N,capacity);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "   Time taken by function: "<< duration.count()*0.000001<< " s" << endl;
 }else if ( opt == 3){
    auto start = high_resolution_clock::now();
    greedyByDensity(profit,weight,density,N,capacity);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "   Time taken by function: "<< duration.count()*0.000001<< " s" << endl;
  }else if ( opt == 4){
    auto start = high_resolution_clock::now();
    greedyBySize(profit,sizes,N,volume);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "   Time taken by function: "<< duration.count()*0.000001<< " s" << endl;
 }
}

