// Time Complexity : O(nlogn)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


struct Item{
    int value;
    int weight;
};

struct Knapsack {
    int value;
    int weight;
    double profit;
};


class Solution
{
    private :
    static bool comp(Knapsack &obj1 , Knapsack &obj2) {
        
        if(obj1.profit > obj2.profit) return true;
        
        return false;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        Knapsack brr[n];
        
        for(int i = 0 ; i < n ; i++) {
            double profitPerWeight = (double) ((double)arr[i].value / arr[i].weight);
            
            brr[i].weight = arr[i].weight;
            brr[i].value = arr[i].value;
            brr[i].profit = profitPerWeight;
        }
        
        sort(brr , brr + n , comp);
        
        double maxProfit = 0.0;
        int remainingWeight = W;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(brr[i].weight <= remainingWeight) {
                maxProfit += brr[i].value;
                remainingWeight -= brr[i].weight;
            } else {
                
                double val = (double) ((double) (brr[i].value * remainingWeight) / brr[i].weight);
                
                maxProfit += val;
                
                break;
            }
        }
        
        return maxProfit;
    }
        
};