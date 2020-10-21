class Solution {
public:

vector <int> sum_total;
int sum = 0;

    Solution(vector<int>& w) {
        //First we need to initialise the sum vector
        //On which we will do a binary search;
        for(int i : w)
        {
                sum += i;
                sum_total.push_back(sum);
        }
    }

    int pickIndex() {
        int indx = rand()% sum;
        return binarySearch(indx+1);
    }
    
    int binarySearch(int value)
    {
        int l=0;
        int r=sum_total.size()-1;
        while (l<r)
        {
            int mid = l+ (r-l)/2;
            if (sum_total[mid] < value)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */



