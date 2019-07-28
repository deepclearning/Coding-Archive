/* Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details. /*
/*https://www.interviewbit.com/problems/anti-diagonals/ */

vector<vector<int> > ans;

void traverse(int i, int j, vector<vector<int> > &A)
{
    vector<int> temp;
    int n = A.size();
    
    while (i < n && j >= 0) {
        temp.push_back(A[i][j]);
        i++;
        j--;
    }
    
    ans.push_back(temp);
}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int dir = 0;
    int i = 0, j = 0;
    ans.clear();
    
    int n = A.size();
    int m = A[0].size();
    
    while (true) {
        if (dir == 0) {
            traverse(i, j, A);
            if (j == m - 1) {
                dir = 1;
                i++;
            }
            else {
                j++;
            }
        }
        
        else if (dir) {
            traverse(i,j,A);
            if (i >= n) {
                break;
            }
            else {
                i++;
            }
        }
        if (i >= n) {
            break;
        }
    }
    
    return ans;
}
