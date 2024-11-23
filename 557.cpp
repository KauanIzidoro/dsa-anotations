#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    string ans;
    map<int, string> subwords;
    vector<int> spaces;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            // subwords.emplace(i,s.substr(0,i));
            spaces.push_back(i);
        }
    }

    // for(auto& [key, value] : subwords)
    // {
    //     cout << key << " " << value << endl;
    // }

    // generate map<key,value> with subwords
    for (int i = 0; i < spaces.size(); i++)
    {
        if (i == 0)
        {
            subwords.emplace(i, s.substr(0, spaces[i]));
        }
        subwords.emplace(i, s.substr(spaces[i] - spaces[i-1]+1, spaces[spaces.size()]-spaces[i] + spaces[i+1]));
        cout << spaces[i] << " " << endl;
    }

    for (auto &[key, value] : subwords)
    {
        cout << key << " " << value << endl;
    }

    return ans;
}

int main()
{
    string s = "Let's take LeetCode contest";
    string ans;
    set<int> spaces;
    vector<string> subwords;
    for (int i = 0; i <= s.length(); i++)
    {
        ans.append(string(1, s[s.length() - i]));
    }
    for (int i = 0; i < ans.length(); i++)
    {
        if (ans[i] == ' ')
        {
            // map the spaces of string
            spaces.insert(i);
        }
    }

    // cout << spaces() << endl;
    //
    // for(set<int>::iterator it = spaces.begin(); it != spaces.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    solve(s);
    cout << ans << endl;
    // cout << ans[22] << ans[17] << ans[8] << endl;

    return 0;
}
