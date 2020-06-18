class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector <int> valIndex;
        SortB (people);
        //valIndex = CreateVal(people);

        //PrintT(people,valIndex);
        //PercP (people,valIndex);
        return people;
    }

    vector <int> CreateVal (vector<vector<int>> vec)
    {
        vector <int> valIndex;
        for (int i =0 ; i<vec.size();i++)      //initialise vector and deque
        {
            valIndex.push_back(0);
            if (i-1>=0 && vec[i-1][0] >= vec[i][0] )
                valIndex[i]=valIndex[i-1]+1;
        }
        return valIndex;
    }

    void PercP(vector<vector<int>> & vec, vector<int> &valIndex)
    {
        bool change = true;

        while (change)
        {
            change = false;
            for (int i=0;i<valIndex.size();i++)
            {
                if (vec[i][1]>valIndex[i])
                {
                    //cout<<"========================"<<endl;
                    //cout<<"change comencing"<<endl;
                    change = true;
                    int moveBy = vec[i][1]-valIndex[i];
                    //cout<<"will move "<<vec[i][0]<<" "<<vec[i][1]<<" by "<<moveBy<<" currently at position "<<i<<endl;
                    for (int j=i;valIndex[j]<vec[j][1];j++)
                    {
                        SwapPosIndex(j,j+1,vec,valIndex);
                        //PrintT(vec,valIndex);
                    }
                }
            }

        }
    }

    template <typename T>
    vector<T> apply_permutation
    (
        const vector<T>& vec,
        const vector<size_t> &p
    )
    {
        std::vector<T> sorted_vec(vec.size());
        std::transform(p.begin(), p.end(), sorted_vec.begin(),
            [&](std::size_t i){ return vec[i]; });
        return sorted_vec;
    }

    template <typename T>
    void apply_permutation_in_place
    (
        std::vector<T>& vec,
        const std::vector<std::size_t>& p
    )
    {
        vector<bool> done(vec.size());
        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (done[i])
            {
                continue;
            }
            done[i] = true;
            size_t prev_j = i;
            size_t j = p[i];
            while (i != j)
            {
                swap(vec[prev_j], vec[j]);
                done[j] = true;
                prev_j = j;
                j = p[j];
            }
        }
    }

    vector<MyObject> vectorA;
    vector<int> vectorB;

    auto p = sort_permutation
        (
         vectorA,
         [](T const& a, T const& b
        )
         { /*some comparison*/ }
         );

    vectorA = apply_permutation(vectorA, p);
    vectorB = apply_permutation(vectorB, p);

    void SortB (vector<vector<int>>&people)
    {
        //this is a horrible sort
        //but I just wanted to get it done quick
        //will change if I have time
        //with a heap sort
        for (int j = 0; j < people.size();j++)
        {
            int minV = people[j][0];
            int posM = j;
            for(int i=j ; i<people.size() ; i++)
            {
                if (people[i][0]<minV)
                {
                    minV = people[i][0];
                    posM = i;
                }
            }
            if ( j != posM)
                SwapPos(j,posM,people);
        }
        return;
    }

    void SwapPos(int pos1, int pos2, vector<vector<int>> &vec)
    {
        int temp0 = vec[pos1][0];
        int temp1 = vec[pos1][1];

        vec[pos1][0]=vec[pos2][0];
        vec[pos1][1]=vec[pos2][1];

        vec[pos2][0]=temp0;
        vec[pos2][1]=temp1;

        return;
    }

    void SwapPosIndex(int pos1, int pos2, vector<vector<int>> &vec, vector <int> &val)
    {
        if(vec[pos2][0] <= vec[pos1][0])
            val[pos2]--;

        if(vec[pos2][0] >= vec[pos1][0])
            val[pos1]++;

        int temp0 = vec[pos1][0];
        int temp1 = vec[pos1][1];
        int temp3 = val[pos1];

        vec[pos1][0]=vec[pos2][0];
        vec[pos1][1]=vec[pos2][1];
        val[pos1]=val[pos2];

        vec[pos2][0]=temp0;
        vec[pos2][1]=temp1;
        val[pos2]=temp3;

        return;
    }

    void PrintT(vector<vector<int>> vec, vector <int> val)
    {
        cout<<endl<<"Priting"<<endl;
        int i=0;
        for (vector<int> t1 : vec)
        {
            cout<<i<<" - ";
            for (int t2 : t1)
            {
                cout<<t2<<" ";
            }
            cout<<val[i]<<endl;
            i++;
        }
    }
};
