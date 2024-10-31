public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        IList<IList<int>> ans = new List<IList<int>>();
        ans.Add(new List<int>{1});
        if(numRows == 1) return ans;
        ans.Add(new List<int>{1,1});
        for(int i = 2 ; i < numRows ; ++i){
            List<int>temp = new List<int>{1};
            for(int j = 0 ; j < ans[i-1].Count-1 ; ++j){
                temp.Add(ans[i-1][j] + ans[i-1][j+1]);
            }
            temp.Add(ans[i-1][ans[i-1].Count-1]);
            ans.Add(temp);
        }
        return ans;
    }
}