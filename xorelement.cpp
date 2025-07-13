class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {

        vector<int> ans;
        int temp = 0;
        int left = 0;
        int right = 0;
        int n = queries.size();
        for (int i = 0; i < n; i++)
        {

            left = queries[i][0];
            right = queries[i][1];

            while (left <= right)
            {
                temp ^= arr[left++];
            }
            ans.push_back(temp);
            temp = 0;
        }

        return ans;
    }
};